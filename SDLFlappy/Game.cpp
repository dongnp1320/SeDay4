#include "Game.h"
#include "TextureManager.h"
#include "Components.h"
#include "Vector2D.h"
#include "Collision.h"
Manager manager;
auto& bird(manager.addEntity());
auto& pipe(manager.addEntity());
//GameObject* player;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		isRunning = true;
	}


	bird.addComponent<TransformComponent>(100.0f, 100.0f, 100, 20, 1);
	bird.addComponent<SpriteComponent>("Asset/bird.png");
	bird.addComponent<KeyboardController>();
	bird.addComponent<ColliderComponent>("bird");

	pipe.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
	pipe.addComponent<SpriteComponent>("Asset/pipe.png");
	pipe.addComponent<ColliderComponent>("pipe");

}

void Game::handleEvents()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	manager.refresh();
	manager.update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}