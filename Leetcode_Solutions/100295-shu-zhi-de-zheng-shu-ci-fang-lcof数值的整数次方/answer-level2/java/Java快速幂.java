# 思路

基本的快速幂求解，注意防止溢出

# 代码
```
class Solution {
    public double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        long cnt = n; // 防溢出
        cnt = Math.abs(cnt);
        double res = 1, step = x;
        while(cnt > 0){
            if((cnt & 1) != 0){
                res *= step;
            }
            cnt >>= 1;
            step *= step;
        }
        return n > 0 ? res: 1 / res;
    }
}
```