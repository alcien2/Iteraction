#
#

void JackKnife(){
	char Results[10];
	int alpha = 1;
	for(alpha = 1; alpha < 11; alpha ++){
		ReturnChi()
		
		} 
void ReturnChi(int i, int j, SuperArrayDim4<Link<MatrixSU2>> & arr, double & beta, TestClass &randomm, double & res, double &Error, int alpha){
	int t = ErrorNum;
	double a[t + 1], b[t + 1], c[t + 1], d[t + 1];
	for(int q = 0; q < t; q ++){
		if((q > ErrorNum - alpha*50) && (i < Errornum -(alpha-1)*50){ contunue;}
		 GetArray(arr, q);
		 a[q] = WilsonLoop<MatrixSU2>(arr, i, j);
	       	b[q] = WilsonLoop<MatrixSU2>(arr, i - 1, j - 1);
		c[q] = WilsonLoop<MatrixSU2>(arr, i, j - 1);
		d[q] = WilsonLoop<MatrixSU2>(arr, i - 1, j);
	}
	a[t] = 0;
	b[t] = 0;
	c[t] = 0;
        d[t] = 0;
	for(int q = 0; q < t; q ++){
		a[t] += a[q];
		b[t] += b[q];
		c[t] += c[q];
		d[t] += d[q];
	}
	a[t] = a[t]/t;
	b[t] = b[t] /t;
	c[t] = c[t] /t;
	d[t] = d[t] /t;
	double erra = 0;
	double errb = 0;
	double errc = 0;
	double errd = 0;
	for(int q = 0; q < t; q ++){
        	erra += (a[t] - a[q])*(a[t] - a[q]);
		errb += (b[t] - b[q])*(b[t] - b[q]);
		errc += (c[t] - c[q])*(c[t] - c[q]);
		errd += (d[t] - d[q])*(d[t] - d[q]);
        }
	erra = sqrt(erra/t/(t - 1));
	errb = sqrt(errb/t/(t - 1));
	errc = sqrt(errc/t/(t - 1));
	errd = sqrt(errd/t/(t - 1));
	res = -log(a[t]*b[t]/c[t]/d[t]);
}
