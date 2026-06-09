### 解题思路
将输入的数字进行反转，如果是反转后的数字和自己相等，就是回文数，反之则不是，注意负数没有回文数，因为-121的回文数是121-，而121-显然不是一个数字

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        int std = x;
        int rev = 0;
        while(x != 0) {
            int pop = x % 10;
            x /= 10;
            rev = rev * 10 + pop;
        }
        if (rev != std || std < 0) {
            return false;
        }
        else {
            return true;
        }
    }
}
```