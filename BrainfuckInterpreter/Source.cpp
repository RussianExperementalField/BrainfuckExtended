#include <iostream>
using namespace std;

int main() {
	char* code;
	char* mem;
	int len;
	int cell;
	cout << "> Write bf code:\n";
	code = new char[256];
	cin.getline(code, 256);
	len = strlen(code);
	mem = new char[1024];
	for (int i = 0;i < 1024;i++) mem[i] = 0;
	cell = 0;
	for (int i = 0;i < len;i++) {
		if (code[i] == '+') {
			mem[cell]++;
		} 
		else if(code[i] == '-') {
			mem[cell]--;
		}
		else if (code[i] == '<') {
			cell--;
		}
		else if (code[i] == '>') {
			cell++;
		}
		else if (code[i] == ',') {
			cin >> mem[cell];
		}
		else if (code[i] == '.') {
			cout << mem[cell];
		}
		else if (code[i] == '[') { // need fix
			if (mem[cell] == 0) {
				int lvl = 1;
				while (lvl) {
					i++;
					if (code[i] == '[') {
						lvl++;
					}
					else if (code[i] == ']') {
						lvl--;
					}
				}
			}
		}
		else if (code[i] == ']') { // need fix
			if (mem[cell] != 0) {
				int lvl = 1;
				while (lvl) {
					i--;
					if (code[i] == ']') {
						lvl++;
					}
					else if (code[i] == '[') {
						lvl--;
					}
				}
			}
		}
	}
	delete code;
	delete mem;
	cin.get();
	return 0;
}