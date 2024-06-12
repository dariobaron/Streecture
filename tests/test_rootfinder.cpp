#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include "../include/rootfinder.hpp"


class Function3{
	double a, b;
public:
	Function3(double a, double b) : a(a), b(b) {}
	double operator()(double x) const{
		return a * x * std::exp(b * x);
	}
};

class Function5{
public:
	double operator()(double x) const{
		return std::sin(x) - 0.5;
	}
};

class Function11{
	unsigned n;
public:
	Function11(unsigned n) : n(n) {};
	double operator()(double x) const{
		return (n*x - 1) / ((n-1) * x);
	}
};

class Function13{
public:
	double operator()(double x) const{
		if (x == 0)	{	return 0;	}
		else		{	return x / std::exp(1/x/x);	}
	}
};


int main(){

{
	double a = -9;
	double b = 31;
	std::vector<std::pair<int,int>> params = {{-40,-1},{-100,-2},{-200,-3}};
	for (auto & p : params){
		Function3 function(p.first, p.second);
		RootFinder solver(function, a, b);
		auto root = solver.root();
		std::cout << "Function3 with params a=" << p.first << " and b=" << p.second;
		std::cout << " has solution x0=" << root;
		std::cout << " with " << solver.iterations() << " iterations" << std::endl;
	}
}

std::cout << std::endl;

{
	double a = 0;
	double b = 1.5;
	Function5 function;
	RootFinder solver(function, a, b);
	auto root = solver.root();
	std::cout << "Function5 has solution x0=" << root;
	std::cout << " with " << solver.iterations() << " iterations" << std::endl;
}

std::cout << std::endl;

{
	double a = 0.01;
	double b = 1;
	std::vector<unsigned> params = {2,5,15,20};
	for (auto & p : params){
		Function11 function(p);
		RootFinder solver(function, a, b);
		auto root = solver.root();
		std::cout << "Function11 with params n=" << p;
		std::cout << " has solution x0=" << root;
		std::cout << " with " << solver.iterations() << " iterations" << std::endl;
	}
}

std::cout << std::endl;

{
	double a = -1;
	double b = 4;
	Function13 function;
	RootFinder solver(function, a, b);
	auto root = solver.root();
	std::cout << "Function13 has solution x0=" << root;
	std::cout << " with " << solver.iterations() << " iterations" << std::endl;
}

std::cout << std::endl;

return 0;
}


