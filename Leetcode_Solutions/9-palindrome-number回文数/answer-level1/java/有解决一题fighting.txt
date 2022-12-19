### 解题思路
不转字符串的解法

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
		if(x == 0)
			return true;
        if(x < 0 || x % 10 == 0)
			return false;
		int xCopy = x;
		int res = 0;
		while(x != 0) {
			int n = res;
			n *= 10;
			int p = x % 10;
			/*if(p=='+' || p=='-') {
				return false;
			}*/
			n += p;
			if(n / 10 != res) {
				return false;
			}
			x /= 10;
			res = n;
		}
		Integer i1 = new Integer(res);
		Integer i2 = new Integer(x);
		return res == xCopy;
    }
}
```
![image.png](https://pic.leetcode-cn.com/555da7ee3e0554934dfc2330cf0a98472bdf474afbe084aa3b87867716d3a861-image.png)
