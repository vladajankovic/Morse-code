#include <iostream>
#include <map>
#include <string>

using namespace std;

class Morsecode {
private:
	map<char, string> table;
	map<string, char> table1;
	void createtable();
public:
	Morsecode() {
		createtable();
	}
	void texttocode(char c);
	void codetotoext(string& s);
};

int main() {
	Morsecode mc;
	int n;
	string s = "";
	while (true) {
		cout << "Select one of the following options:" << endl
			<< "1. Text to Morse code" << endl
			<< "2. Morse code to text" << endl
			<< "3. Exit program" << endl
			<< "Option num: ";
		cin >> n;
		switch (n) {
		case 1: {
			cout << endl << "Enter \"+\" to stop input! Now Type!" << endl;
			char t = getchar();
			while (true) {
				char c = getchar();
				if (c == 10) {
					cout << endl;
					continue;
				}
				if (c == '+') break;
				if (isupper(c)) c = tolower(c);
				mc.texttocode(c);
			}
			break;
		}
		case 2: {
			cout << endl << "Enter \"+\" to stop input! Now Type!" << endl;
			char t = getchar();
			while (true) {
				char c = getchar();
				if (c == 10) {
					mc.codetotoext(s);
					cout << endl;
					continue;
				}
				if (c == '+') break;
				if (c == '.' || c == '-') {
					string s1 = c == '.'?".":"-";
					s.append(s1);
					continue;
				}
				
				mc.codetotoext(s);
			}
			break;
		}
		case 3: n = -1;
		}
		
		cout << endl;
		if (n == -1) break;
	}
	cout << "Program finished." << endl;

	return 0;
}


void Morsecode::createtable()
{
	table1[".-"] = 'a';
	table1["-..."] = 'b';
	table1["-.-."] = 'c';
	table1["-.."] = 'd';
	table1["."] = 'e';
	table1["..-."] ='f' ;
	table1["--."] = 'g';
	table1["...."] = 'h';
	table1[".."] = 'i';
	table1[".---"] = 'j';
	table1["-.-"] = 'k';
	table1[".-.."] = 'l';
	table1["--"] = 'm';
	table1["-."] = 'n';
	table1["---"] = 'o';
	table1[".--."] = 'p';
	table1["--.-"] = 'q';
	table1[".-."] = 'r';
	table1["..."] = 's';
	table1["-"] = 't';
	table1["..-"] = 'u';
	table1["...-"] = 'v';
	table1[".--"] = 'w';
	table1["-..-"] = 'x';
	table1["-.--"] = 'y';
	table1["--.."] = 'z';
	table1[".----"] = '1';
	table1["..---"] = '2';
	table1["...--"] = '3';
	table1["....-"] = '4';
	table1["....."] = '5';
	table1["-...."] = '6';
	table1["--..."] = '7';
	table1["---.."] = '8';
	table1["----."] = '9';
	table1["-----"] = '0';
	table['a'] = ".-";
	table['b'] = "-...";
	table['c'] = "-.-.";
	table['d'] = "-..";
	table['e'] = ".";
	table['f'] = "..-.";
	table['g'] = "--.";
	table['h'] = "....";
	table['i'] = "..";
	table['j'] = ".---";
	table['k'] = "-.-";
	table['l'] = ".-..";
	table['m'] = "--";
	table['n'] = "-.";
	table['o'] = "---";
	table['p'] = ".--.";
	table['q'] = "--.-";
	table['r'] = ".-.";
	table['s'] = "...";
	table['t'] = "-";
	table['u'] = "..-";
	table['v'] = "...-";
	table['w'] = ".--";
	table['x'] = "-..-";
	table['y'] = "-.--";
	table['z'] = "--..";
	table['1'] = ".----";
	table['2'] = "..---";
	table['3'] = "...--";
	table['4'] = "....-";
	table['5'] = ".....";
	table['6'] = "-....";
	table['7'] = "--...";
	table['8'] = "---..";
	table['9'] = "----.";
	table['0'] = "-----";
}


void Morsecode::texttocode(char c)
{
	if (c == '.') {
		cout << endl; return;
	}
	if (c == ' ') {
		return;
	}
	cout << table[c] << " ";
}

void Morsecode::codetotoext(string& s)
{
	if (!s.empty()) {
		cout << table1[s] << " ";
	}
	s = "";
}
