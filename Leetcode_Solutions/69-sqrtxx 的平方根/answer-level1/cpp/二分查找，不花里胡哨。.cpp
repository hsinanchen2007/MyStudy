### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/2756fb8faddf4a4ab82de9210372935ed0d41c7481834914db4ced0bd1a7c5d7-%E6%8D%95%E8%8E%B7.PNG)


### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
		if (x <= 3) return 1;
		int i = 0, j = x;
		long mid = 0;
		while (i + 1 != j)
		{
			mid = (i + j) / 2;
			if (mid*mid > x) j = mid;
			else if (mid*mid < x) i = mid;
			else break;
		}
		if (mid*mid == x) return mid;
		else return i;
    }
};
```