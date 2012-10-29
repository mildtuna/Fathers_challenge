#include <stdio.h>
#include <SDL.h>

// �Լ�����
void Render();

// ��������
SDL_Surface *screen;  // ������ â�� ��ũ�� ���ǽ�

int main(int argc,char **argv)
{
	SDL_Init(SDL_INIT_VIDEO); // SDL�� �ʱ�ȭ�մϴ�./

	screen = SDL_SetVideoMode(640,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	// â�� �����մϴ�.
	// SDL_SetVideoMode( â����ũ��, ����ũ��, Bpp, �÷��� );
 
	bool quit = false;  // ���� �÷���
	SDL_Event event;  // �̺�Ʈ ������ �޾ƿ� ����

	while(!quit)
	{
		if(SDL_PollEvent(&event)) // SDL �̺�Ʈ ť�� �̺�Ʈ�� �ִ��� �����մϴ�.
		{  
			switch(event.type) // �̺�Ʈ�� Ÿ�Կ� ���� �з��մϴ�.
			{ 
			case SDL_QUIT: // ���� �̺�Ʈ�ϰ�� 
				quit = true; // ���� �÷��׸� ����
				break;
			}
		}

		Render();  // ȭ�� ������ �Լ��� ȣ��

		SDL_Delay(1); // 1�� ���
	}


	SDL_Quit(); // SDL����
	return 0;
}

// ȭ���� ������ �ϴ� �Լ�
void Render()
{
	SDL_Flip(screen); // ������ �� ����� ȭ������ ����Դϴ�.
}