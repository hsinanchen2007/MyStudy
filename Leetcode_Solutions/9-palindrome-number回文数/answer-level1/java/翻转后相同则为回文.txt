### 解题思路
负数为不是回文先排除，然后给当前整数进行翻转，如果和原值相同则是回文。

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0) return false;

	        if(x == reverse(x)) {
	        	return true;
	        } else {
				return false;
			}
    }

     public  int reverse(int x) {
			//检查输入值大小
			if (x > Integer.MAX_VALUE || x < Integer.MIN_VALUE)
				return 0;
			long rs = 0;
			for (; x != 0; rs = rs * 10 + x % 10, x /= 10)
				;
			//检查转换后大小
			return (rs > Integer.MAX_VALUE || rs < Integer.MIN_VALUE) ? 0 : (int) rs;
		}
}
```