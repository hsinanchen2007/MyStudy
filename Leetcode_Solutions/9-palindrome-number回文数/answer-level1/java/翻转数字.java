### 解题思路
翻转数字，除以10 和取模，原数字，截取后，和拼接到新数字个比较一次，存在相等的话是回文数，当新数字大于原数字，则后面不肯是回文数。

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        int temp = 0;
		while (temp <= x) {
			if (x == temp) {
				return true;
			}
			int aaa = x % 10;
			x = x / 10;
			if (x == temp) {
				return true;
			}
			temp = temp * 10 + aaa;
			if (temp == 0) {
				return false;
			}
		}
		return false;
    }
}
```