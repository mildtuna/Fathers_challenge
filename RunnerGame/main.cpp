#include <stdio.h>
#include <SDL.h>

// 함수원형
void Render();

// 전역변수
SDL_Surface *screen;  // 생성한 창의 스크린 서피스

int main(int argc,char **argv)
{
	SDL_Init(SDL_INIT_VIDEO); // SDL을 초기화합니다./

	screen = SDL_SetVideoMode(640,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	// 창을 생성합니다.
	// SDL_SetVideoMode( 창가로크기, 세로크기, Bpp, 플래그 );
 
	bool quit = false;  // 종료 플래그
	SDL_Event event;  // 이벤트 정보를 받아올 변수

	while(!quit)
	{
		if(SDL_PollEvent(&event)) // SDL 이벤트 큐에 이벤트가 있는지 조사합니다.
		{  
			switch(event.type) // 이벤트를 타입에 따라 분류합니다.
			{ 
			case SDL_QUIT: // 종료 이벤트일경우 
				quit = true; // 종료 플래그를 설정
				break;
			}
		}

		Render();  // 화면 렌더링 함수를 호출

		SDL_Delay(1); // 1초 대기
	}


	SDL_Quit(); // SDL종료
	return 0;
}

// 화면을 렌더링 하는 함수
void Render()
{
	SDL_Flip(screen); // 렌더링 한 결과를 화면으로 출력함니다.
}