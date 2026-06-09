### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int digit = (int)Math.floor(Math.log10((double)x)) + 1;
        int y = x;
        for (int i = 1; i < digit/2 + 1; i++) {
            if((x/(int)Math.pow(10,(digit-i)))%10 != y%10){
                return false;
            }
            y = y/10;
        }
        return true;
    }
}
```