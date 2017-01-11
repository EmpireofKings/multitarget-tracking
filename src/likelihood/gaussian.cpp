#include "gaussian.hpp"

Gaussian::Gaussian(double m, double s){
    mean= m;
    sd = s;
}

Gaussian::Gaussian(VectorXd& data){
    mean= data.sum()/data.size();
    sd = sqrt((data.array()-mean).square().matrix().sum()/data.size());
}

double Gaussian::getMean(void){
    return mean;
}
void Gaussian::setMean(double n){
    mean = n;
}

void Gaussian::setSd(double n){
    sd=n;
}
double Gaussian::likelihood(double test){

    return (1.0/sqrt(2*M_PI*pow(sd,2)))*exp(-pow(test-mean,2)/(2*pow(sd,2)));
}
double Gaussian::log_likelihood(double test){
    return (log(1.0)-log(sqrt(2*M_PI*sd*sd+1e-30))-(test-mean)*(test-mean)/(2*sd*sd+1e-30));
}

