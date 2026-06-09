注意，数组中的数字为0~9，即十进制每位上的数字，高位低地址（Big Endian）。
从后往前计算，即从低位开始计算，每次计算都要取模，并且计算下一位。
```
class Solution {
	int powmod(int a, int n, int m){
		int res=1;
		for(; n; a=(a*a)%m, n>>=1)
			if(n&1) res=(res*a)%m;
		return res;
	}
public:
	int superPow(int a, vector<int>& b) {
		int res=1;
		for(int i=b.size(), am=a%1337; i--; am=powmod(am,10,1337))
			res=(res*powmod(am,b[i],1337))%1337;
		return res;
	}
};
```

![2019-06-19 17-40-25屏幕截图.png](https://pic.leetcode-cn.com/c786ba0257341148c2e75102609629b6560e727a11f845e3307e0e0bf89274b0-2019-06-19%2017-40-25%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)