#include <iostream>
#include <random>
#include <vector>
#include "../include/tree.hpp"

int main(){

std::random_device rd;
std::mt19937 rng(rd());

auto edges = Tree::generateYuleEdges(rng, 100);
for (auto & edge : edges){
	std::cout << edge.parent << " " << edge.child << std::endl;
}

Tree tree(edges);

auto depths = tree.computeDepths();
for (auto & depth : depths){
	std::cout << depth << " ";
}
std::cout << std::endl;

double B2 = tree.computeB2();
std::cout << B2 << std::endl;

double B2norm = tree.computeB2Norm();
std::cout << B2norm << std::endl;

return 0;
}