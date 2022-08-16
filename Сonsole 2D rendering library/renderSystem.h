#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <Windows.h>
#include "colors.h"

// Feature of the system: 
// If the object has a black background, it is not rendered(= transparent).
// To remove this feature, delete the check for a black background in the "DrawChar" method (69-70 lines in .cpp)

struct RenderObject;

class RenderSystem
{
private:
	static const int s_default_screenY = 20;
	static const int s_default_screenX = 40;

	const int _screenY;
	const int _screenX;

	RenderObject** _backBuffer;
	RenderObject** _screenBuffer;

	HANDLE _consoleHandle;

public:
	RenderSystem(const int screenY, const int screenX);
	RenderSystem();
	~RenderSystem();

	void Render();
	void Clear();
	void DrawChar(int y, int x, const RenderObject& object);
	void DrawBackground(int y, int x, Color backgroundColor);
	void SendText(int y, int x, const char* text, Color symbolColor = Color::gray, Color backgroundColor = Color::black);

private:
	bool CompareBuffers(const RenderObject* buf_1, const RenderObject* buf_2) const;
	void SetColor(Color symbolColor, Color backgroundColor);
	void SetColor(Color symbolColor);
	void SetDefault();
	void SetCursor(int Y, int X);
	void HideCursor();
	void ShowCursor();
};

struct RenderObject
{
	unsigned char symbol;	// Symbol on the visual map (after render)
	Color symbolColor;		// Symbol color
	Color backgroundColor;	// Background color
};
#endif // !RENDERSYSTEM_H