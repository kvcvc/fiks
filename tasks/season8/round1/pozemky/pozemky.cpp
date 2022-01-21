#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		int celkova_plocha = 0;
		for (int i = 0; i < N; i++) {
			string zvire;
			int objednany_jedinci;
			int vymer_vybehu;
			cin >> zvire >> objednany_jedinci >> vymer_vybehu;
			celkova_plocha += objednany_jedinci * vymer_vybehu;
		}
		cout << celkova_plocha << "\n";
	}
}
