#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string in;
	cin >> in;
	int res = in[in.size() - 1];
	res &= 15;
	cout << res << endl;

	return 0;
}
