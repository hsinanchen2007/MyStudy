### 解题思路
(a * b) % p = (a % p * b % p) % p 
先写一个求次方的函数。
由于次方b给的是数组，直接转为数字求次方也会导致溢出，所有转为每个位上的次方，下一轮开始的时候求个10次方。
### 代码

```cpp
class Solution {
public:
	int qpow(int a, int b, int m)
	{
		int res = 1;
		while (b)
		{
			if (b & 1)res = (res * a) % m;
			a = (a % m) * (a % m) % m;
			b >>= 1;
		}
		return res;
	}
	int superPow(int a, vector<int>& b) {
		int n = 0, res = 1;
		for (int x : b) res = qpow(res,10,1337) * qpow(a, x, 1337) % 1337;
		return res;
	}
};
```