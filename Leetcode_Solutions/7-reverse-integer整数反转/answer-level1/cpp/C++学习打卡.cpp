### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	int reverse(int x) {
		int reverseNum = 0;
		while (x != 0) {
			int curDigit = x % 10;
			x = x / 10;
			if (reverseNum > INT_MAX / 10 || (reverseNum == INT_MAX / 10 && curDigit > 7)) {
				return 0;
			}
			if (reverseNum < INT_MIN / 10 || (reverseNum == INT_MIN / 10 && curDigit < -8)) {
				return 0;
			}
			reverseNum = reverseNum * 10 + curDigit;
		}
		return reverseNum;
	}
};
```