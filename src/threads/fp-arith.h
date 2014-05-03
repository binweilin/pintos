#ifndef THREADS_FP_ARITH_H
#define THREADS_FP_ARITH_H

/*B.6 Fixed-point Real Arithmetic

Let x and y be fixed-point numbers, and let n be an integer. 
Convert n to fixed point:	n * f
Convert x to integer (rounding toward zero):	x / f
Convert x to integer (rounding to nearest):	(x + f / 2) / f if x >= 0, 
(x - f / 2) / f if x <= 0.
Add x and y:	x + y
Subtract y from x:	x - y
Add x and n:	x + n * f
Subtract n from x:	x - n * f
Multiply x by y:	((int64_t) x) * y / f
Multiply x by n:	x * n
Divide x by y:	((int64_t) x) * f / y
Divide x by n:	x / n
*/
int conv_int_to_fp(int n); //convert int to fixed point
int conv_fp_to_int_zero(int fp_x); //convert fix point to int 
int conv_fp_to_int_nearest(int fp_x); //convert fix point to int
int add_fp_and_fp(int fp_x, int fp_y); //add two fix point
int sub_fp_from_fp(int fp_x, int fx_y); //subract fix point from fix point
int add_fp_and_int(int fp_x, int n); //add a fix point and an int
int sub_int_from_fp(int fp_x, int n); //subract int from fix point
int mul_fp_by_fp(int fp_x, int fp_y); //multiply two fix points
int mul_fp_by_int(int fp_x, int n); //multiply fp by int
int div_fp_by_fp(int fp_x, int fp_y);//divide two fix points
int div_fp_by_int(int fp_x, int n); //divide fix points by int

#define f (1 << 14)

//convert int to fixed point
int
conv_int_to_fp(int n){
	 return n * f;	
}

//convert fix point to int
//rounding toward zero
int
conv_fp_to_int_zero(int fp_x){
	return fp_x/f;
}

//convert fix point to int
//rounding to nearest
int
conv_fp_to_int_nearest(int fp_x){

	if(fp_x >= 0){
		return (fp_x-f/2)/f;
	}
	else{
		return (fp_x+f/2)/2;
	}
}

//add two fix point
int
add_fp_and_fp(int fp_x, int fp_y){
	return fp_x + fp_y;
}

//subract fix point from fix point
int
sub_fp_from_fp(int fp_x, int fp_y){
	return fp_x - fp_y;
}

//add a fix point and an int
int
add_fp_and_int(int fp_x, int n){
	return fp_x + n * f;
}

//subract int from fix point
int
sub_int_from_fp(int fp_x, int n){
	return fp_x - n * f;
}

//multiply two fix points
int
mul_fp_by_fp(int fp_x, int fp_y){
	return ((int64_t) fp_x) * fp_y / f;
}

//multiply fp by int
int
mul_fp_by_int(int fp_x, int n){
	return fp_x * n;
}

//divide two fix points
int
div_fp_by_fp(int fp_x, int fp_y){
	return ((int64_t) fp_x) * f / fp_y;
}

//divide fix point by int
int
div_fp_by_int(int fp_x, int n){
	return fp_x / n;
}

#endif
