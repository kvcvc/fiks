#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;

	for ( int i = 0; i < N; i++) {
		long double W, H, X, Y, T;
		cin >> W >> H >> X >> Y >> T;

		long double S = pow(T + 1, 2);

		long double odriznuti_pretekani[4][2] = {{X, T - X}, {Y, T - Y}, {W - X - 1.0, T - W + X + 1.0}, {H - Y - 1.0, T - H + Y + 1.0}};
		for ( int i = 0; i < 4; i++) {
			long double podminka = odriznuti_pretekani[i][0];
			long double n = odriznuti_pretekani[i][1];
			if (T > podminka) {
				S -= (n + 1) * n/2;
			}
		}

		long double vraceni_spolecnych[4][2] = {{Y, X}, {Y, W - X - 1.0}, {W - X - 1.0, H - Y - 1.0}, {X, H - Y - 1.0}};
		for ( int i = 0; i < 4; i++) {
			long double A = vraceni_spolecnych[i][0];
			long double B = vraceni_spolecnych[i][1];
			long double n;
			long double a1;
			if (T - A - B >= 2) {
				if (fmod((T - A - B), 2.0) == 0) {
					n = (T - A - B) / 2;
					a1 = 1;
				} else {
					n = (T - A - B - 1) / 2;
					a1 = 2;
				}
				
				S += (2 * a1 + (n - 1) * 2) * n/2;
			}
		}

		printf("%0.0Lf\n", S);
	}
}