#include "random.h"

RandomNumbers::RandomNumbers(unsigned long int s) { //non si mettono le variabili par default
	
	if( s == 0){
		std::random_device rd;
		seed = rd();
	}else{
		seed = s;
	}
	rng = std::mt19937(seed);
}

void RandomNumbers::uniform_double(std::vector<double>& vector, double lower, double upper){
	
	for(auto& el: vector){
		el = uniform_double(lower,upper);
	}
}

double RandomNumbers::uniform_double(double lower, double upper){
	
	std::uniform_real_distribution<double> distribution(lower,upper);
	return distribution(rng);
}

void RandomNumbers::normal(std::vector<double>& vector, double mean, double sd){
	
	for(auto& el: vector){
		el = normal(mean,sd);
	}
}

double RandomNumbers::normal(double mean, double sd){
	
	std::normal_distribution<double> distribution(mean,sd);
	return distribution(rng);
}

void RandomNumbers::poisson(std::vector<int>& vector, double mean){
	
	for(auto& el: vector){
		el = poisson(mean);
	}
}

int RandomNumbers::poisson(double mean){
	
	std::poisson_distribution<int> distribution(mean);
	return distribution(rng);
}
