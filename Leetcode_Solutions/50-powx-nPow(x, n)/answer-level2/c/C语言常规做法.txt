```c
double myPow(double x, int n){
    if(n==-2147483648) return 1/x*myPow(1/x, 2147483647);
    if(n<0){
        x=1/x;
        n=-n;
    }
    if(n==0) return 1;
    if(n==1) return x;
    if(n%2==0) return myPow(x*x,n/2);
    else return myPow(x*x,n/2)*x;
}
```