### 解题思路
![image.png](https://pic.leetcode-cn.com/3b1464fd6ba26020f48ff9aca68cc05bd6ac013a38c583cff853e1ce39abbb6d-image.png)


### 代码

```cpp
class Solution {
public:
int dp(int n, int log_10)
{
	if (log_10 == 0)
		return n >= 2 ? 1 : 0;
	int po = pow(10, log_10);
	int firstBit = n / po;
	int res = 0;
	res += dp(n%po, log_10 - 1);
	res += (firstBit)*dp(po - 1, log_10 - 1);
	if (firstBit == 2)
	{
		res += n % po+1;
	}
	else if (firstBit > 2)
		res += po ;
	return res;
}
    int numberOf2sInRange(int n) {
        if(n==0)return 0;
        int log_10;
	for (log_10 = 0; pow(10, log_10) <= n; log_10++);
	log_10--;
	return dp(n, log_10);
    }
};
```