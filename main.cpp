#include <iostream>
#include <string>
#include "jh_ref.h"

using namespace std;

int main(void) {
	const int hashbitlen = 512;
	const DataLength dlen = hashbitlen / 8;
	BitSequence reshash[dlen];
	BitSequence data[dlen];
	//int rounds = 42; //original
	cin >> data;
	for (int rounds = 10; rounds <= 60; rounds++) {
		size_t change_cnt = 0;
		HashReturn status = Hash(hashbitlen, data, dlen, reshash, rounds);
		for (size_t i = 0; i < (size_t) dlen; i++) {
			if (data[i] != reshash[i]) {
				change_cnt++;
			}
		}
		cout << rounds << "\t" << change_cnt << endl;
	}
	return 0;	
}
