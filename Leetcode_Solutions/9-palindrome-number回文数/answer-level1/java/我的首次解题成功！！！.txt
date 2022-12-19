### 解题思路


### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        long rs = 0;
		long y = x;
		while (y!=0) {
			rs = rs*10 + y%10;
			y = y/10;
		}
		if (rs>=0&&rs==x) {
			return true;
		}else {
			return false;
		}
    }
}
```