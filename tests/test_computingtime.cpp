#include <fstream>
#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include "../streecture.hpp"

std::ofstream output;


int main(){

std::random_device rd;
std::mt19937 rng(rd());

output.open("times.txt", std::ios::trunc);
output.close();

std::vector<unsigned> sizes = {10000,20000,40000,80000,160000,320000,640000,1280000,2560000,5120000,10240000,20480000,40960000};

for (auto size : sizes){
	auto start = std::chrono::steady_clock::now();

	auto edges = Tree::generateYuleEdges(rng, size);
	auto afteredges = std::chrono::steady_clock::now();
	auto edgecreation = std::chrono::duration_cast<std::chrono::milliseconds>(afteredges - start).count();
	
	Tree tree(edges);
	auto aftertree = std::chrono::steady_clock::now();
	auto treecreation = std::chrono::duration_cast<std::chrono::milliseconds>(aftertree - afteredges).count();

	auto b2norm = tree.computeB2Norm();
	auto afterb2 = std::chrono::steady_clock::now();
	auto b2computation = std::chrono::duration_cast<std::chrono::milliseconds>(afterb2 - aftertree).count();

	auto total = std::chrono::duration_cast<std::chrono::milliseconds>(afterb2 - start).count();

	output.open("times.txt", std::ios::app);
	output << "For size=" << size << ":\n";
	output << "edge generation took " << edgecreation << " ms\n";
	output << "tree generation took " << treecreation << " ms\n";
	output << "metric computation took " << b2computation << " ms\n";
	output << "In total took " << total << " ms\n" << std::endl;
	output.close();

	std::cout << "Computing size " << size << std::endl;

//	if (size > 1e6)	{	break;	}
}



return 0;
}