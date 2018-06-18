#include <iostream>
#include <string>
#include "jh_ref.h"

using namespace std;

int main(void) {
	const int hashbitlen = 512;
	const int byte_size = 8;
	const DataLength dlen = hashbitlen / byte_size;
	BitSequence reshash[dlen];
	BitSequence data[dlen];
	//int rounds = 42; //original
	cin >> data;
	for (int rounds = 10; rounds <= 60; rounds++) {
		size_t change_cnt = 0;
		HashReturn status = Hash(hashbitlen, data, dlen, reshash, rounds);
		for (size_t i = 0; i < (size_t) dlen; i++) {
			if (data[i] != reshash[i]) {
				change_cnt += byte_size;
			}
		}
		if (status == SUCCESS) {
			cout << rounds << "\t" << change_cnt << endl;
		} else {
			cout << "ERROR" << endl;
		}
	}
	return 0;	
}
