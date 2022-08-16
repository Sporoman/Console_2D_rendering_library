#include "renderSystem.h"

static const int SIZE_Y = 10;
static const int SIZE_X = 21;

const char c_objects_map[SIZE_Y][SIZE_X + 1]
{
	"####################",
	"#                  #",
	"#         B M  C   #",
	"#     B   H        #",
	"#           H      #",
	"#             ]    #",
	"#     H      ]     #",
	"#   C     M        #",
	"#                  #",
	"####################"
};

const char c_background_map[SIZE_Y][SIZE_X + 1]
{
	"####################",
	"#-1234567812345678-#",
	"#                  #",
	"#-1234567812345678-#",
	"#                  #",
	"#-1234567812345678-#",
	"#                  #",
	"#-1234567812345678-#",
	"#                  #",
	"####################"
};

unsigned char GetRenderSymbol(unsigned char symbol);
Color GetColorSymbol(unsigned char symbol);
Color GetColorBackground(unsigned char symbol);


int main()
{
	RenderSystem renSys(10,20);

	// Fulling render map
	for (int y = 0; y < SIZE_Y; ++y)
		for (int x = 0; x < SIZE_X; ++x)
		{
			// Draw background
			renSys.DrawBackground(y, x, GetColorBackground(c_background_map[y][x]));

			// Draw map object
			RenderObject obj;
			obj.symbol = GetRenderSymbol(c_objects_map[y][x]);
			obj.symbolColor = GetColorSymbol(c_objects_map[y][x]);
			obj.backgroundColor = GetColorBackground(c_objects_map[y][x]);

			renSys.DrawChar(y, x, obj);
		}
			
	// Start render
	renSys.Render();

    return 0;
}


unsigned char GetRenderSymbol(unsigned char symbol)
{
	switch (symbol)
	{
		case ' ':	return ' ';
		case 'H':	return 2;
		case '#':	return 177;
		case ']':	return 21;
		case 'B':	return 254;
		case 'C':	return 4;
		case 'M':	return 15;

		default: return '?';
	}
}

Color GetColorSymbol(unsigned char symbol)
{
	switch (symbol)
	{
		case ' ':	return Color::black;
		case 'H':	return Color::yellow;
		case '#':	return Color::white;
		case ']':	return Color::blue;
		case 'B':	return Color::brown;
		case 'C':	return Color::magenta;
		case 'M':	return Color::green;

		default: return Color::red;
	}
}

Color GetColorBackground(unsigned char symbol)
{
	switch (symbol)
	{
		case '#':
		case '0':    return Color::black;
		case '1':    return Color::darkBlue;
		case '2':    return Color::darkGreen;
		case '3':    return Color::darkCyan;
		case '4':    return Color::darkRed;
		case '5':    return Color::darkMagenta;
		case '6':    return Color::brown;
		case '7':    return Color::white;
		case '8':    return Color::gray;
		case '-':    return Color::darkGray;

		default: return Color::black;
	}
}