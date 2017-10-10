#include "conio.h"
#include "cstdlib"
#include <fstream>
#include <iostream>
#include "vector"
#include "string"
#include "time.h"
#include "windows.h"


using namespace std;

/////////////////////////////

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

void SetColor(ConsoleColor text, ConsoleColor background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

class letters
{
private:
	struct el
	{
		char letter;
		int count;
		el* next;
	};

	el* top;

public:

	letters()
	{
		top = NULL;

		el* new_firstEl = new el;
		new_firstEl->letter = 'a';
		new_firstEl->count = 0;

		top = new_firstEl;

		el* saveTop = top;

		for (int i = 98; i <= 122; i++)
		{
			el* newEl = new el;
			newEl->letter = i;
			newEl->count = 0;
			top->next = newEl;
			top = newEl;
		}
		top = saveTop;
	}
	void addCount(char letter)
	{
		el* tempEl = top;
		for (int i = 0; i < 26; i++)
		{
			if (tempEl->letter == letter)
				tempEl->count = 1;
			else
				tempEl = tempEl->next;
		}
	}
	int operator[](char letter)
	{
		el* tempEl = top;
		for (int i = 0; i < 26; i++)
		{
			if (tempEl->letter == letter)
			{
				int saveCount = tempEl->count;
				tempEl->count = 0;
				return saveCount;
			}
			else
				tempEl = tempEl->next;
		}
	}
};

/////////////////////////////

class hackSystem
{
private:
	
	struct level
	{
		int length;
		string levelName;
	};
	string truePass;
	level gameLevel;
	vector<string> passMass;
	vector<int> indexMass;
	vector<string> usePass;

public:

	hackSystem();
	void display();
	void hack();

	void win();
	void gameOver();
	
	void menu();
	void setting();
	void authors();	
	void setLevel();
	string toLower(string);
	char getTrashSymbol();
	void clearValue();
	bool checkPassRelevance(string);
};


hackSystem::hackSystem()
{
	gameLevel.length = 0;
	gameLevel.levelName = "indf";
}

string hackSystem::toLower(string word)
{
	for (int i = 0; i < word.length(); i++)
		word[i] = tolower(word[i]);
	return word;
}

void hackSystem::menu()
{
	string choice;
	do
	{
		system("cls");
		cout << "\n======================================/***\\====================================="
			"||       ____   ____                                    ____     ___          ||"
			"||      |      |    |  |      |                |    |  |    |   /     | /     ||"
			"||      |____  |____|  |      |                |____|  |____|  |      |/      ||"
			"||      |      |    |  |      |                |    |  |    |  |      |\\      ||"
			"||      |      |    |  |____  |____            |    |  |    |   \\___  | \\     ||"
			"||                                                                            ||"
			"======================================\\***/=====================================\n";

		cout << "\n================================================================================\n"
			"\n\t\t\t       ~~~BETA - V 0.3~~~\n"
			"\n\t\t\t      *START - Начать игру;"
			"\n\t\t\t      *SETTING - Настройки;"
			"\n\t\t\t      *AUTHORS - Создатели;"
			"\n\t\t\t      *EXIT - Выход;"
			"\n\n_: ";

		cin >> choice;
		cin.get();
		cin.clear();
		choice = toLower(choice);

		if (choice == "start")
		{
			setLevel();
			display();
			hack();
			continue;
		}
		else if (choice == "setting")
		{
			setting();
			continue;
		}
		else if (choice == "authors")
		{
			authors();
			continue;
		}
		else if(choice != "exit")
		{
			cout << "\n\t\t\t\t     Ошибка!\n\t\t\t      Некорректная команда.\n\n\n\t\t   ";

			system("pause");
		}
	} while (choice != "exit");
}

void hackSystem::setting()
{
	while (1)
	{
		system("cls");

		string choice;
		cout << "\n======================================/***\\====================================="
			"\n\n\t\t\t\t  ***SETTING***"
			"\n\n\t\t\t    Выберите пункт цвета:\n"
			"\n\t\t\t1. Фон: Черный; Текст: Белый"
			"\n\t\t\t2. Фон: Черный; Текст: Красный"
			"\n\t\t\t3. Фон: Черный; Текст: Зелёный"
			"\n\t\t\t4. Фон: Черный; Текст: Голубой"
			"\n\t\t\t5. Фон: Белый; Текст: Черный"
			"\n\t\t\t6. Фон: Синий; Текст: Белый\n\n\n"
			"_: ";

		cin >> choice;

		switch (choice[0])
		{
			case ('1'):
			{
				system("color 0F");
				cout << "\n\n\t\t      Цвет фона и текста успешно изменён.\n\n\n\t\t   ";
				system("pause");
				return;
			}
			case ('2'):
			{
				system("color 0C");
				cout << "\n\n\t\t      Цвет фона и текста успешно изменён.\n\n\n\t\t   ";
				system("pause");
				return;
			}
			case ('3'):
			{
				system("color 0A");
				cout << "\n\n\t\t      Цвет фона и текста успешно изменён.\n\n\n\t\t   ";
				system("pause");
				return;
			}
			case ('4'):
			{
				system("color 0B");
				cout << "\n\n\t\t      Цвет фона и текста успешно изменён.\n\n\n\t\t   ";
				system("pause");
				return;
			}
			case('5'):
			{
				system("color F0");
				cout << "\n\n\t\t      Цвет фона и текста успешно изменён.\n\n\n\t\t   ";
				system("pause");
				return;
			}
			case('6'):
			{
				system("color 9F");
				cout << "\n\n\t\t      Цвет фона и текста успешно изменён.\n\n\n\t\t   ";
				system("pause");
				return;
			}
			default:
			{
				cout << "\n\n\t\t\t\t    Ошибка!\n\t\t\tВыберите один из приведённых пунктов.\n\n\n\t\t   ";
				system("pause");
				break;
			}
		}
	}
}

void hackSystem::authors()
{
	system("cls");
	cout << "\n======================================/***\\====================================="
		"\n\n\t\t\t\t  ***AUTHORS***"
		"\n\n\t\t\t    Создатель - Берникович Алексей"
		"\n\t\t\t    Поддержка - Алина Сахар"
		"\n\t\t\t    Тестирование - Евгений Андреевич"
		"\n\t\t\t    Идея - Bethesda Softworks\n\n\n\n\t\t\t";
	system("pause");
}

void hackSystem::setLevel()
{
    do 
    {
        system("cls");
        cout << "\n======================================/***\\====================================="
            "\n\n\t\t\t\t  ***SET LEVEL***"
            "\n\n\t\t\t    Выберите уровень сложности:\n"
            "\n\t\t\t   VERY EASY	(Пароль: 4 букв)"
            "\n\t\t\t   EASY		(Пароль: 5 букв)"
            "\n\t\t\t   NORMAL	(Пароль: 6 букв)"
            "\n\t\t\t   HARD		(Пароль: 7 букв)\n\n\n"
            "_: ";


        string u_Level;
		getline(cin,u_Level);
        u_Level = toLower(u_Level);

        if (u_Level == "very easy")
        {
            gameLevel.length = 4;
            gameLevel.levelName = "very_easy.txt";
            break;
        }

        if (u_Level == "easy")
        {
            gameLevel.length = 5;
            gameLevel.levelName = "easy.txt";
            break;
        }

        if (u_Level == "normal")
        {
            gameLevel.length = 6;
            gameLevel.levelName = "normal.txt";
            break;
        }

        if (u_Level == "hard")
        {
            gameLevel.length = 7;
            gameLevel.levelName = "hard.txt";
            break;
        }

        cout << "\n\n\t\t\t\t    Ошибка!\n\t\t\t  Неверный уровень сложности!\n\n\n\t\t   ";
        system("pause");

    } while (gameLevel.length == 0);

	ifstream getPass("Data//Pass//" + gameLevel.levelName);
	
	while (!getPass.eof())
	{
		string pass;
		getPass >> pass;
		passMass.push_back(pass);
	}

	for (int i = 0; i < passMass.size(); i++)
		indexMass.push_back(i);

	for (int i = 0; i < indexMass.size(); i++)
		swap(indexMass[i], indexMass[rand() % indexMass.size()]);

}

char hackSystem::getTrashSymbol()
{
	return rand() % 14 + 33;
}

bool hackSystem::checkPassRelevance(string uPass)
{

	for (int i = 0; i < usePass.size(); i++)
	{
		if (uPass == usePass[i])
			return true;
	}
	return false;

}

void hackSystem::display()
{
	system("cls");

	cout << "\n================================================================================\n";

	const int size = 20;

	int index = 0;

	bool findedTurePass = false;

	int indexTruePass = rand() % 9 + 1;

	for (int column = 0; column < size; column++)
	{
		int iWordOne = rand() % (37 - gameLevel.length) + 1;
		int iWordTwo = rand() % (37 - gameLevel.length) + 41;

		for (int i = 1; i <= 80; i++)
		{
			if (i == 38)
			{
				cout << "|  |";
				i = 42;
			}

			if ((rand() % 3) == 1)
			{
				if (i == iWordOne)
				{
					cout << passMass[indexMass[index]];
					string temp = passMass[indexMass[index]];
					temp = toLower(temp);
					usePass.push_back(temp);
					i += gameLevel.length;
					index++;
				}

				if (i == iWordTwo)
				{
					cout << passMass[indexMass[index]];
					string temp = passMass[indexMass[index]];
					temp = toLower(temp);
					usePass.push_back(temp);
					i += gameLevel.length;
					index++;
				}

				if (index == indexTruePass && !findedTurePass)
				{
					truePass = passMass[indexMass[index]];
					findedTurePass = true;
				}
			}
			cout << getTrashSymbol();
		}
	}
}

void hackSystem::hack()
{
	truePass = toLower(truePass);
	letters lettersList;
	volatile int choice = 3;

	while(choice != 0)
	{
		cout << "\n================================================================================\n";
		cout << " Количество попыток: " << choice;
		cout << "\n\n_: ";
		string pass;
		cin >> pass;
				
		if (pass.length() != gameLevel.length)
		{
			cout << "\n Количество символов должно быть не меньше: " << gameLevel.length << "\n\n ";

			system("pause");
		}
		else
		{
			pass = toLower(pass);

			if (checkPassRelevance(pass))
			{
				if (pass == truePass)
				{
					win();
					return;
				}
				else
				{
					choice--;
					for (volatile int i = 0; i < gameLevel.length; i++)
					{
						for (volatile int j = 0; j < gameLevel.length; j++)
						{
							if (pass[i] == truePass[j])
							{
								lettersList.addCount(pass[i]);
								break;
							}
						}
					}

					volatile int count = 0;

					for (volatile int k = 97; k <= 122; k++)
					{
						count += lettersList[k];
					}

					cout << "\n Неверный пароль!\n\n Количество совпадений: " << count << "\n\n ";

					system("pause");
				}
			}
			else
			{
				cout << "\n\t\t\t\tОшибка!\n\n\t\t\t" << pass << " - недопустимый пароль.\n\n\n ";

				system("pause");
			}
		}
	}
	gameOver();
	return;	
}

void hackSystem::win()
{
	system("cls");
	cout << "\n======================================/|||\\=====================================\n";
	cout << "\n\n\n\n\n\n\n\t\t\t  Вы успешно взломали терминал!\n\n\t\t\t\t     . . .\n\n\n\t\t   ";
	system("pause");

	clearValue();

}

void hackSystem::gameOver()
{
	const int timeSet = 700;

	for (int i = 0; i < 3; i++)
	{

		system("cls");
		cout << "\n\n\t\t________========GAME OVER========________\n\n\n\n";
		cout << "                           00000000000000000000"
			"\n                         000000000000000000000000"
			"\n                       0000000000000000000000000000 "
			"\n                     00000000000000000000000000000000  "
			"\n                    0000000000000000000000000000000000 "
			"\n                   000000000000000000000000000000000000"
			"\n                   000000000000000000000000000000000000"
			"\n                   00000   0000000000000000000    00000"
			"\n                   0000       00000000000000       0000"
			"\n                   0000         0000000000         0000"
			"\n                   0000          00000000          0000"
			"\n                   000000       0000000000       000000"
			"\n                   000000000000000000000000000000000000"
			"\n                     0000000000000  00  0000000000000"
			"\n                      00000000000   00   00000000000"
			"\n                        00000000    00    00000000"
			"\n                        000000000   00   00000000"
			"\n                        00000000000000000000000000"
			"\n                            000000000000000000"
			"\n                        00  000000000000000000  00"
			"\n                        00   0000000000000000   00"
			"\n                         000   000000000000   000"
			"\n                          0000              0000"
			"\n                            000000000000000000"
			"\n                              00000000000000"
			"\n                                0000000000";

		Sleep(timeSet);

		system("cls");
		cout << "\n\n\t\t________========GAME OVER========________\n\n\n\n";
		cout << "                           00000000000000000000"
			"\n                         000000000000000000000000"
			"\n                       0000000000000000000000000000 "
			"\n                     00000000000000000000000000000000  "
			"\n                    0000000000000000000000000000000000 "
			"\n                   000000000000000000000000000000000000"
			"\n                   000000000000000000000000000000000000"
			"\n                   00000   0000000000000000000    00000"
			"\n                   0000       00000000000000       0000"
			"\n                   0000         0000000000         0000"
			"\n                   0000          00000000          0000"
			"\n                   000000       0000000000       000000"
			"\n                   000000000000000000000000000000000000"
			"\n                     0000000000000  00  0000000000000"
			"\n                      00000000000   00   00000000000"
			"\n                        00000000    00    00000000"
			"\n                        000000000   00   00000000"
			"\n                        00000000000000000000000000"
			"\n                            000000000000000000"
			"\n                            000000000000000000"
			"\n                        00   0000000000000000   00"
			"\n                        00     000000000000     00"
			"\n                         000                  000"
			"\n                          0000              0000"
			"\n                            000000000000000000"
			"\n                              00000000000000"
			"\n                                0000000000";

		Sleep(timeSet);
	}

	cout << "\n\n\n\t\t      Вы не смогли взломать терминал.\n\t\t\t      Игра окончена.\n\n\n\n\t\t";
	system("pause");

	clearValue();
}

void hackSystem::clearValue()
{
	truePass = "";
	gameLevel.length = 0;
	gameLevel.levelName = "";

	passMass.clear();
	indexMass.clear();
	usePass.clear();
}

int main()
{
	setlocale(0, "Russian");
	srand(time(0));

	system("MODE CON: COLS=80 LINES=70");
	system("color 0a");

	hackSystem one;

	one.menu();

	return 0;
}