### 解题思路
此处撰写解题思路,同整数反转的思路，将整数反转后确认值有没有变化，如果同有变化的话，则认为是TURE，否则为FALSE

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        int orginx = x;
        if(x >= Integer.MAX_VALUE || x <= Integer.MIN_VALUE ) return false;
        int remainder = 0;
        int result = 0;
        while ( Math.abs(x) >= 10){
            remainder = x % 10 ;
            int consult = x / 10 ;
            result = result * 10 + remainder  ;
            x = consult;
        }
        if(Math.abs(result) > Integer.MAX_VALUE/10 || result < Integer.MIN_VALUE /10) return false;
        if (orginx == result * 10  + x) return true;
        return false;
    }
}
```