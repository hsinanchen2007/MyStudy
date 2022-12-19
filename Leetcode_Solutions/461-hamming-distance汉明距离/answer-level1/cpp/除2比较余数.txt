### 解题思路
除2比较余数（相当于一步步二进制化）

### 代码

```cpp
class Solution {
public:
	int hammingDistance(int x, int y) {
		int count = 0;
		for (int i = 0; i < 31; i++)
		{
			int yushu1 = x % 2;int yushu2 = y % 2;
			x = (x - yushu1) / 2;y = (y - yushu2) / 2;
			if (yushu1 != yushu2)
				count++;
		}
		return count;
	}
};
```