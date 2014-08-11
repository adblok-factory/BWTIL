/*
 * main.cpp
 *
 *  Created on: Jun 15, 2014
 *      Author: nicola
 */

#include "../../data_structures/DummyDynamicBitvector.h"
#include "../../extern/bitvector/include/bitvector.h"

using namespace bwtil;
using namespace bv;

 int main(int argc,char** argv) {

	 ulint N = 50000;

	DummyDynamicBitvector bv_naive(N);
	bitvector_t<4096, alloc_on_demand> bv_Btree(N,1024);

	//bitvector_t<4096, alloc_on_demand>::test(std::cout, 100000, 512, false, false, false);

	srand(time(NULL));

	bool rand_bit;
	ulint rand_pos;

	cout << "Inserting bits ..."<< flush;

	for(ulint i=0;i<N;i++){

		rand_bit = rand()%2;
		rand_pos = rand()%(i+1);

		bv_naive.insert(rand_bit,rand_pos);
		bv_Btree.insert(rand_pos,rand_bit);

	}

	cout << "done."<< endl;

	info_t info = bv_Btree.info();
	cout << "d = " << info.degree << endl;
	cout << "b = " << info.buffer << endl;

	cout << "Checking correctness..."<< endl;

	for(ulint i=0;i<N;i++){

		if(bv_naive.access(i) != bv_Btree.access(i)){

			cout << "ERROR: naive bv and Btree bv do not coincide\n";
			exit(1);

		}

	}

	cout << endl;

	cout << "Success! " << endl;

 }



