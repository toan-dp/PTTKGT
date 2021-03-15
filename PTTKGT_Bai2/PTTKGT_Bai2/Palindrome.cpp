#include <iostream>
#include <conio.h>
#include <string>
#include <vector>

using namespace std;

void check(vector<char> p) {
	//Luoc bo ki tu dac biet:													// n = p.size()
	for (int i = 0; i < p.size(); i++) {										// 10:     n+1
		if (int(p[i]) < 65 || int(p[i] > 122)) {									//
			p.erase(p.begin() + i, p.begin() + i + 1);
			i--;
		}
		else {
			if (int(p[i]) >= 91 && int(p[i] <= 96)) {
				p.erase(p.begin() + i, p.begin() + i + 1);
				i--;
			}
		}
	}

	// Chuyen chu thuong => chu in hoa
	for (int t = 0; t < p.size(); t++)											// 24:    n+1
	{
		if (islower(p[t])) {
			p[t] = toupper(p[t]);
		}
	}


	// check
	vector<char> s = p;															//          1

	int i = 0;																	//			1
	int j = s.size() - 1;														//			1
	int mid = s.size() / 2 + s.size() % 2;										//			1					
	float kq = true;															//			1

	while (i <= mid) {															//			n/2 + 1
		if (int(s[i]) == int(s[j - i]))
		{
			i++;
			continue;
		}
		else
		{
			kq = false;
			break;
		}
	}

	// in Ket qua
	if (kq) {																	//			1
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}
																				// T = n+1 + n+1 + 1*5 + n/2+1 + 1 = 2n + 9 + n/2 = 5n/2 + 9
																				// => O la: O(n) 
int main() {

	vector<char> p = { 'm','a',' ','+','*','d','a','_','M' };

	check(p);

	return 0;
}