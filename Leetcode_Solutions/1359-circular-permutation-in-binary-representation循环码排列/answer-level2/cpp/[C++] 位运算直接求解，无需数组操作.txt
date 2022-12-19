定义二进制码（B）与对应的格雷码（G），如下表：
![二进制码与格雷码.png](https://pic.leetcode-cn.com/e1faccde11cdda7605bd320a3da9745095998e6754192740f27de2a9108b1d66-%E4%BA%8C%E8%BF%9B%E5%88%B6%E7%A0%81%E4%B8%8E%E6%A0%BC%E9%9B%B7%E7%A0%81.png)
二进制码转格雷码：G = B ^ B >> 1；格雷码转二进制码：B = ^(G >> i), i = 0 .. n - 1, n为格雷码二进制位数。
输入中start为格雷码，转换成二进制码后通过枚举其后的二进制码即可求解。
程序如下：
```C++ []
class Solution
{
public:
	vector<int> circularPermutation(int n, int start)
	{
		vector<int> v = { start };
		int b = start;
		while (start >>= 1)
			b ^= start;
		n = (1 << n) - 1;
		for (int i = 1; i <= n; i++)
			v.push_back(b + i & n ^ (b + i & n) >> 1);
		return v;
	}
};
```