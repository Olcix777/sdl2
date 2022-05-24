#include <iostream>
#include <SDL.h>
#include<string>
#include<fstream>


void myDrawRectangle(unsigned int* canvas, unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int max_w, unsigned int max_h)
{

	unsigned int* start = &(canvas[(x + max_w * y) - 1]);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			start[j + i * max_w] = 0x0000FF00;
		}

}

void DisplayPPM(std::string& filename, );

int main(int argc, char** argv)
{
	bool leftMouseButtonDown = false;
	bool quit = false;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("SDL2 Pixel Drawing",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Texture* texture = SDL_CreateTexture(renderer,
		SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, 640, 480);
	Uint32* pixels = new Uint32[640 * 480];
	memset(pixels, 255, 640 * 480 * sizeof(Uint32));
	myDrawRectangle(pixels, 60, 40, 100, 50, 640, 480);


	while (!quit)
	{
		SDL_UpdateTexture(texture, NULL, pixels, 640 * sizeof(Uint32));

		SDL_WaitEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
				leftMouseButtonDown = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
				leftMouseButtonDown = true;
		case SDL_MOUSEMOTION:
			if (leftMouseButtonDown)
			{
				int mouseX = event.motion.x;
				int mouseY = event.motion.y;
				//pixels[mouseY * 640 + mouseX] = 0;
			}
			break;
		}

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	delete[] pixels;
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}