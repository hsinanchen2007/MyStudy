### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution 
{
public:
	int hammingWeight(uint32_t n) 
	{
		int count = 0;
		if (n == 0) return 0;
		while (n != 0)
		{
			if (n & 1)
				count++;
			n >>= 1;
		}
		return count;
	}
};
```