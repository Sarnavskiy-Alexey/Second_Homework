#include <iostream>

// All tic-tac-toe possible symbols
enum E_TTT_Symbol
{
	cCross = 'X',
	cZero = 'O',
	cEmpty = ' '
};

// Tic-tac-toe structure
struct TTT_characteristics
{
	E_TTT_Symbol aGame[3][3];			// field for Tic-Tac-Toe
	char aPlayer_1_Name[21];			// first player name: 20 symbols max
	char aPlayer_2_Name[21];			// second player name: 20 symbols max
	E_TTT_Symbol first_player;			// what symbol first player play
	E_TTT_Symbol second_player;			// what symbol second player play
	unsigned bGameIsOver : 1;			// true - end, false - not end
	unsigned bDraw : 1;					// true - draw, false - not draw
	unsigned bWinner : 1;				// true - first player, false - second player
	unsigned short iCount_Wins_1_pl;	// counts wins of the first player
	unsigned short iCount_Wins_2_pl;	// counts wins of the second player
};

// union MyData
union T_MyData
{
	int i;
	float f;
	char c;
};

// MyVariant structure
struct T_MyVariant
{
	unsigned isInt : 1;
	unsigned isFloat : 1;
	unsigned isChar : 1;
	T_MyData MyData;
};

// 
void WriteMyVariantStructure(T_MyVariant& tmp, int x)
{
	tmp.MyData.i = x;
	tmp.isInt = 1;
	tmp.isFloat = 0;
	tmp.isChar = 0;
}

void WriteMyVariantStructure(T_MyVariant& tmp, float x)
{
	tmp.MyData.f = x;
	tmp.isInt = 0;
	tmp.isFloat = 1;
	tmp.isChar = 0;
}

void WriteMyVariantStructure(T_MyVariant& tmp, char x)
{
	tmp.MyData.c = x;
	tmp.isInt = 0;
	tmp.isFloat = 0;
	tmp.isChar = 1;
}

void Print(T_MyVariant tmp)
{
	std::cout << "\tisInt is:\t\t" << tmp.isInt << std::endl
		<< "\tisFloat is:\t\t" << tmp.isFloat << std::endl
		<< "\tisChar is:\t\t" << tmp.isChar << std::endl;
}

int main()
{
	/* Variables initialization */
	short iVar_16bit = 0;				// short int variable
	int nVar = 0;						// int variable
	long long llVar = 0LL;				// long long variable
	char cVar = '\0';					// char variable
	bool bVar = false;					// bool variable
	float fVar = 0.0f;					// float variable
	double dVar = 0.0;					// double variable

	/* Array initialization */
	E_TTT_Symbol aGame[3][3] =			// array from some game
	{
		{ cEmpty, cCross, cEmpty },
		{ cZero, cEmpty, cCross },
		{ cEmpty, cZero, cEmpty }
	};

	std::cout << "These is the game field from some game Tic-Tac-Toe:\n";
	for (int loc_i = 0; loc_i < 3; loc_i++)
	{
		for (int loc_j = 0; loc_j < 3; loc_j++)
		{
			std::cout << " " << (char)aGame[loc_i][loc_j] << " |";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	/* T_MyVariant variable initialization */
	T_MyVariant loc_MV_Variable = {0, 0, 0, 0};

	/* Example of using T_MyVariant variable like int */
	WriteMyVariantStructure(loc_MV_Variable, 123456);
	std::cout << "Here remains int variable:\t" << loc_MV_Variable.MyData.i << std::endl;
	Print(loc_MV_Variable);
	std::cout << "In other vars there are trash:\n"
		<< "Float var: " << loc_MV_Variable.MyData.f << std::endl
		<< "Char var: " << loc_MV_Variable.MyData.c << std::endl << std::endl;

	/* Example of using T_MyVariant variable like float */
	WriteMyVariantStructure(loc_MV_Variable, 1.23456e-6f);
	std::cout << "Here remains float variable:\t" << loc_MV_Variable.MyData.f << std::endl;
	Print(loc_MV_Variable);
	std::cout << "In other vars there are trash:\n"
		<< "Int var: " << loc_MV_Variable.MyData.i << std::endl
		<< "Char var: " << loc_MV_Variable.MyData.c << std::endl << std::endl;

	/* Example of using T_MyVariant variable like char */
	WriteMyVariantStructure(loc_MV_Variable, 'a');
	std::cout << "Here remains char variable:\t" << loc_MV_Variable.MyData.c << std::endl;
	Print(loc_MV_Variable);
	std::cout << "In other vars there are trash:\n"
		<< "Int var: " << loc_MV_Variable.MyData.i << std::endl
		<< "Float var: " << loc_MV_Variable.MyData.f << std::endl << std::endl;
	return 0;
}
