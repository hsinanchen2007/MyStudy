超简单的java解法，你甚至不用带脑子hh
```
class Solution {
    public int reverse(int x) {
        long res = 0;
        int flag = -1;
        if(x < 0) x = -x;
        else flag = 1;
        while(x != 0){
            res = res * 10 + x % 10;
            x /= 10;
        }
        res *= flag;
        if(res > Integer.MAX_VALUE || res < Integer.MIN_VALUE) return 0;
        else return (int)res;
    }
}
```
