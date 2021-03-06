#ifndef LOGISTIC_H
#define LOGISTIC_H
#include <iostream>
#include <stdlib.h>
#include <cfloat>
#include <cmath>
#include <algorithm>
#include <vector>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Cholesky>
#include "../utils/c_utils.hpp"

using namespace Eigen;
using namespace std;


class LogisticRegression
{
 public:
 	LogisticRegression();
	void init(bool _normalization = false, bool _standardization = false,bool _with_bias=false);
	void init(MatrixXd &_X,VectorXd &_Y,double lambda=1.0, bool _normalization = false, bool _standardization = true,bool _with_bias=true);
 	double logPosterior();
 	void setWeights(VectorXd &_W);
    void setData(MatrixXd &_X,VectorXd &_Y);
 	VectorXd getWeights();
 	double getBias();
 	void setBias(double bias);
 	double getGradientBias();
 	//MatrixXd computeHessian(MatrixXd &_X, VectorXd &_Y, VectorXd &_W);
 	RowVectorXd featureMean,featureStd,featureMin,featureMax;
 	bool initialized = false;
 	virtual double train(int n_iter,double alpha,double tol) = 0 ;
 	virtual VectorXd predict(MatrixXd &_X_test, bool prob=false, bool data_processing = true) = 0;

 protected:
 	VectorXd weights;
 	MatrixXd *X_train;
 	VectorXd *Y_train;
	VectorXd eta,phi;
	VectorXd momemtum;
 	int rows,dim;
 	double lambda,bias,grad_bias;
 	bool normalization, standardization, with_bias;
 	VectorXd sigmoid(VectorXd &_eta);
 	//VectorXd logSigmoid(VectorXd &_eta);
 	double logPrior();
 	double logLikelihood();
 	MatrixXd Hessian;
 	C_utils tools;
	virtual void preCompute() = 0;
 	virtual VectorXd computeGradient() = 0;
    //MVNGaussian posterior;
};

#endif
