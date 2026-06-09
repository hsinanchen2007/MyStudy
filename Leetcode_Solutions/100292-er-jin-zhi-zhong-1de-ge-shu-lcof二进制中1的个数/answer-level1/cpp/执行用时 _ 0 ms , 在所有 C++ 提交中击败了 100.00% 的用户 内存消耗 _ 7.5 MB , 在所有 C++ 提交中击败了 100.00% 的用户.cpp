### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;
		for (int i = 0; i < 32;i++) {
			int nn = n & 1;
			if (nn ^ 1 == 0) {
				count++;
			}
			n=n >> 1;
		}
		return count;
	}
};
```