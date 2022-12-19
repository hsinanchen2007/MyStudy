### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int source = x;
        int rev = 0;
        while (x>0) {
            int pop = x % 10;
            rev = pop + rev * 10;
            x /= 10;
        }

        if (source == rev) {
            return true;
        }

        return false;
    }
}
```