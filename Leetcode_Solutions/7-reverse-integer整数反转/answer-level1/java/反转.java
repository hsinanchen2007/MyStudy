### 解题思路
对每个数据先除以10，直到最终的商小于10，同时每次余数乘以10，就可以将数据反转了。
一定要注意数据的范围，输入的数据不能大于超出范围，同理，反转后的数据也不能超出范围

### 代码
```java
class Solution {
    public int reverse(int x) {
        //对每个数据先除以10，直到最终的商小于10，每次余数乘以10
        if(x >= Integer.MAX_VALUE || x <= Integer.MIN_VALUE ) return 0;
        int remainder = 0;
        int result = 0;
        while ( Math.abs(x) >= 10){
            remainder = x % 10 ;
            int consult = x / 10 ;
            result = result * 10 + remainder  ;
            x = consult;
        }
        if(Math.abs(result) > Integer.MAX_VALUE/10) return 0;
        return result * 10  + x;
    }
}
```