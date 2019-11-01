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
	
	std::uniform_real_distribution<double> distribution(lower,upper);
	for(auto& el: vector){
		el = distribution(rng);
	}
}

double RandomNumbers::uniform_double(double lower, double upper){
	
	std::uniform_real_distribution<double> distribution(lower,upper);
	return distribution(rng);
}

void RandomNumbers::normal(std::vector<double>& vector, double mean, double sd){
	
	std::normal_distribution<double> distribution(mean,sd);
	for(auto& el: vector){
		el = distribution(rng);
	}
}

double RandomNumbers::normal(double mean, double sd){
	
	std::normal_distribution<double> distribution(mean,sd);
	return distribution(rng);
}

void RandomNumbers::poisson(std::vector<int>& vector, double mean){
	
	std::poisson_distribution<int> distribution(mean);
	for(auto& el: vector){
		el = distribution(rng);
	}
}

int RandomNumbers::poisson(double mean){
	
	std::poisson_distribution<int> distribution(mean);
	return distribution(rng);
}
