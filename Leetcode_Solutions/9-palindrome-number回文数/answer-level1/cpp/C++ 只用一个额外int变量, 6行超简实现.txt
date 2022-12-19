![image.png](https://pic.leetcode-cn.com/2b3cc71358506314f92ed39340592b13a5bcd06fb61f58f4229438f9c0e98c2b-image.png)
执行用时4ms, 击败99.4% + 100%
### 解题思路
拿x的前一半与后一半对比。
1. 若x为0-9, true
2. 若x最末位为0, 即 x%10 = 0, false
3. 如果x<0, false
4. 若x位数为偶, 则若前后半段相等 true
5. 若x位数为奇, 则前后半段若较长数/10 = 较短数, true
		例 x = 12321, 则分为 123和12, 较长数的末位为对称轴

### 代码

```cpp
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 10 && x >= 0) return true;
		if (x < 0 || x % 10 == 0) return false;
		int val = 0;
		for (; val * 10 <= x; x /= 10) //构造x的前半段与后半段, 前半段为x, 后半段为val
			val = val * 10 + x % 10;
		return (val == x || (val > 9 && val / 10 == x));
	}
};
```