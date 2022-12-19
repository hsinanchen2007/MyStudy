先找到这个数前面有多少个0，leading0，然后制作一个（32-leading0）位的全1掩码，再用它跟目标值的求反与一下。
```
int leading0 = getLeadingZeros(num);
uint32_t mask  = (uint32_t)(1<<(32-leading0) - 1；
return mask & (~num);
```

![image.png](https://pic.leetcode-cn.com/7c1dd1ded02b2fe9d970caf2d0492b0aabf6a83533ead815f1e715bf907b0485-image.png)
```
class Solution {
public:
	int findComplement(int num) {
        uint32_t holder = (uint32_t)num;
		uint32_t leading0 = leadingZeros(holder);
        uint32_t mask = (uint32_t)(1<<(32-leading0)) - 1;
        return mask & (uint32_t)(~holder);
	}
private:
	int leadingZeros(int num)
	{
		int pos = 0;
		int len = 16;
		while (len > 0)
		{
			if (num > 1 << len)
			{
				pos += len;
				num >>= len;
			}
			len = len / 2;
		}
		return 31 - pos;
	}
};
```