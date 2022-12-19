### 解题思路
直接将原数字进行翻转得到新数字，然后与原数字比较是否相等就可以了。

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)){
            return false;
        }
        int reverse = 0;
        int r = 0;
        int orgin = x;
        while ( x != 0 ){
            r = x % 10;
            reverse = reverse * 10 + r;
            x /= 10;
        }
        if (reverse == orgin){
            return true;
        }
        return false;
    }
}
```