### 解题思路
递归

### 代码

```cpp
class Solution {
public:
	int addDigits(int num) {
		int sum = num % 10 + num / 10;
		if (sum < 10)
			return sum;
		return addDigits(sum);
	}
};
```