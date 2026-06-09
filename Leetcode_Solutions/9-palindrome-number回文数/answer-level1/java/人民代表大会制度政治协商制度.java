### 解题思路
夹逼准则

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0)
            return false ;
        if (x ==0)
            return true ;
        int len = (int)Math.log10(x) + 1 ;
        while (len > 1) {
            len -- ;
            int high = x / (int)Math.pow(10,len) ;
            x = x -  high*(int)Math.pow(10,len)  ;
            len -- ;
            int low = x % 10 ;
            x = x / 10 ;
            if (high != low)
                return false ;
        }
        return true ;
    }
}
```