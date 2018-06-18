#include <iostream>
#include <string>
#include "jh_ref.h"

using namespace std;
const int HASHBITLEN = 512;
const int BYTE_SIZE = 8;
const int ROUNDS_RANGE_BEGIN = 10;
const int ROUNDS_RANGE_END = 61;

int main(void) {
	const DataLength dlen = HASHBITLEN / BYTE_SIZE;
	BitSequence reshash[dlen];
	BitSequence data[dlen];
	//int rounds = 42; //original
	cin >> data;
	size_t summ = 0;
	for (int rounds = ROUNDS_RANGE_BEGIN; rounds < ROUNDS_RANGE_END; rounds++) {
		size_t change_cnt = 0;
		HashReturn status = Hash(HASHBITLEN, data, dlen, reshash, rounds);
		for (size_t i = 0; i < (size_t) dlen; i++) {
			BitSequence mask = 1;
			for (size_t j = 0; j < BYTE_SIZE; j++) {
				if ((data[i] & mask) != (reshash[i] & mask)) {
					change_cnt++;
				}
				mask = mask << 1;
			}
		}
		if (status == SUCCESS) {
			summ += change_cnt;
			cout << rounds << "\t" << change_cnt << endl;
		} else {
			cout << "ERROR" << endl;
		}
	}
	long double middle = (long double) summ / (long double) (ROUNDS_RANGE_END - ROUNDS_RANGE_BEGIN);
	cout << endl << "Middle = " << middle << endl;
	return 0;
}
