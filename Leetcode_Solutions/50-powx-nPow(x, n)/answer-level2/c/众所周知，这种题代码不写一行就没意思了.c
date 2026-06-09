### 代码

```c
double myPow(double x, int n){
return x==0? 0:n==0x80000000 ?myPow(1.0/x,0x7FFFFFFF)*(1.0/x):n<0?myPow(1.0/x,-n): n==0 ?  1 :n&1 ? myPow(x*x,n>>1)*x :myPow(x*x,n>>1);
}
```