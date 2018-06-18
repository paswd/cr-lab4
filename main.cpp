#include <iostream>
#include <string>
#include "jh_ref.h"

using namespace std;

int main(void) {
	const int hashbitlen = 256;
	BitSequence reshash[hashbitlen / 8];
	const DataLength dlen = 256;
	BitSequence data[dlen];
	int rounds = 42;
	cin >> data;
	HashReturn status = Hash(hashbitlen, data, dlen, reshash, rounds);
	cout << reshash << endl;
	return 0;	
}
