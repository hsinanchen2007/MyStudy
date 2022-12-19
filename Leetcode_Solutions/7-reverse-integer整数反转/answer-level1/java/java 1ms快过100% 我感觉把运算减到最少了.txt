```
class Solution {
    public int reverse(int x) {
        if (x == 0) {
            return 0;
        }
        int p = 1;
        if (x < 0) {
            p = -1;
            if ( x == Integer.MIN_VALUE) {     // MIN_VALUE反转后溢出
                return 0;
            }else {
                x = -x;
            }
        }
        
        int max_int_10 = Integer.MAX_VALUE / 10;
        int result = 0;
        while( x != 0 ){
            if (result > max_int_10) {  // 如果当前值 > Integer.MAX_VALUE / 10, 那 *10 后溢出
                return 0;
            }
            result *= 10;
            result += x % 10;
            x /= 10;
        }
        if( result < 0 ){   // 有了上面的检查，即使溢出了，result也必小于0
            return 0;       // 应该多余的，不放也可以过，而且我也想不出case。但是感觉放上来安心一点。
        }
        return result * p;
    }
}
```
