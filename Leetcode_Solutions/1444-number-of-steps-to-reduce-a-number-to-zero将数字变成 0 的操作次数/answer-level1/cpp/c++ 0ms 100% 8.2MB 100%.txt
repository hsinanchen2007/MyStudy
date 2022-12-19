### 解题思路
奇数减一后就是偶数，也就是说奇数需要2次操作，而这两次操作分别是先减一再除以二，又因为位运算右移相当于除以二向下取整，对于奇数来说就正好是减一再除以二，所以我们每次循环只需要做两件事情，右移和判断是否为奇数。
### 代码

```cpp
class Solution {
public:
    int numberOfSteps(int num) {
		int nCount = 0;
		while (num) {
			if (1 == (num & 1)) {
				nCount++;
			}
			num = num >> 1;
			nCount++;
		}
		return nCount - 1;
	}
};
```