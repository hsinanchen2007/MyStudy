class Solution {
public:
```
int f(int n){//计算1到n含的5的因子数 
	int sum=0;
	while(n>=0&&n%5)//0到n中最大的5的倍数 
		n--;
	n/=5;//求5的倍数
	while(n){
		sum+=n;
		n/=5;//某些项不止一个5的因子，例如25（5*5）
	}
	return sum; 
}
int trailingZeroes(int n) {
	//2*5=10，有多少2、5对，即有多少0
	//并且5远比2少，所以只要知道5的因子数即可
 	return f(n); 
}
```	
};