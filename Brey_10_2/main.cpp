#include <iostream>//для cin cout
#include <fstream>//для ifstream/ofstream
#include <string>//для getline и сложени¤ строк

using namespace std;

int find(string& line, string& word)
{
	//текущее слово
	string curWord;
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == ' ' || line[i] == '.') //если встретили пробел или точку - слово кончилось
		{
			bool equals = true; //изначально считаем равными
			//если длины слов равны
			if (curWord.length() == word.length())
			{
				for (int k = 0; k < curWord.length(); k++)
				{
					//проверяем посимвольно
					if (curWord[k] != word[k])
					{
						//если хотя бы 1 символ отличается
						equals = false; //слова не равны
						break;
					}
				}
			}
			else
			{
				equals = false;
			}
			if (equals)
			{
				//индекс старта слова
				return i - curWord.length(); //если нашли искомое слово - сразу возврат
			}
			curWord.erase();
			continue; //не переписываем символ
		}
		curWord += line[i]; //переписываем 1 символ из строки в слово
	}
	return -1;
}

void remove(string& line, string& word)
{
	string nline; //новая строка после удаления
	string curWord; //текущее слово
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == ' ' || line[i] == '.') //если встретили пробел или точку - слово кончилось
		{
			bool equals = true; //изначально считаем равными

			if (curWord.length() == word.length())
			{
				for (int k = 0; k < curWord.length(); k++)
				{
					//проверяем посимвольно
					if (curWord[k] != word[k])
					{
						//если хотя бы 1 символ отличается
						equals = false; //слова не равны
						break;
					}
				}
			}
			else
			{
				equals = false; //если длины слов не равны
			}
			if (!equals) //если слова не равны - переписываем
			{
				//посимвольно переписываем символы из слова в строку
				for (int k = 0; k < curWord.length(); k++)
				{
					nline += curWord[k];
				}
				nline += " "; //в конце пробел
			}
			curWord.erase();
			continue; //не переписываем символ
		}
		curWord += line[i]; //переписываем 1 символ из строки в слово
	}
	line = nline; //пересохраняем строку
}

int main()
{
	setlocale(LC_ALL, "russian");

	cout << "Программу сделала Брей Валерия студент группы УМЛ-112\n";
	cout << "Программа для поиска символа в строке\n";

	ifstream f1("f1.txt");
	ofstream f2("f2.txt");

	string word;
	cout << "Введите слово для поиска: ";
	cin >> word;

	while (!f1.eof())
	{
		string line;
		std::getline(f1, line); //считать строку
		while (int index = find(line, word) != -1)
		{
			cout << "Найдено слово!" << "\n";
			remove(line, word);
		}

		f2 << line + "\n"; //вывести строку в файл
	}

	f1.close();
	f2.close();

	system("pause");
	return 0;
}
