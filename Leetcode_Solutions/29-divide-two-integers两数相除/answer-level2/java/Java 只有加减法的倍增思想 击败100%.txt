## 倍增思想
 移位操作其实也算是乘除法操作，也算犯规。
以79/3 = 26为例.
维护两个int变量: sum和ans
ans意味着你需要ans个divisor之和去逼近dividend, sum是当前的累积和。
ans = 1, sum = divisor = 3.
**Step1:**
    sum = sum + sum = 6, ans = ans + ans = 2
    sum = sum + sum = 12, ans = ans + ans = 4
    ...
    sum = 24 + 24 = 48, ans = 8 + 8 = 16
    remain = 79 - 48 = 31
**Step2:**
    Recursion:
    sum = 3 + 3 = 6, ans = 1 + 1 = 2
    ...
    sum = 12 + 12 = 24, ans = ans + ans = 8
    remain = 31 - 24 = 7
**Step3:**
    Recurse until remain < divisor, return 0


```
class Solution {
    public int divide(int dividend, int divisor) {
        if( divisor == 1 ) {
            return dividend;
        }
        if( divisor == -1 ){
            if( dividend > Integer.MIN_VALUE ) {
                return -dividend; 
            }  // 只要不是最小的那个整数，都是直接返回相反数就好啦
            return Integer.MAX_VALUE;// 是最小的那个，返回最大的整数
        }
        
        boolean isNeg = false;
        if( (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) ) {
            isNeg = true;
        }
        long temp = (long)(dividend);
        long dividend2 = Math.abs(temp);
        temp = (long)(divisor);
        long divisor2 = Math.abs(temp);
        
        if( dividend2 < divisor2 ) {
            return 0;
        }
        // Binary Search
        // Double the curSum 
        // recursion
        int ans = (int)divideHelper(dividend2, divisor2);
        return isNeg ? -ans : +ans;
    }

    private long divideHelper(long dividend, long divisor) {
        
        if( dividend < divisor ) {
            return 0;
        }
        
        long ans = 1;
        long curSum = divisor;
        // int Overflow Long
        while( curSum + curSum <= dividend ) {
            curSum = curSum + curSum;  // double the sum
            ans = ans + ans;  // double the quotient
        }

        long remain = dividend - curSum;
        
        return ans + divideHelper(remain, divisor);  // Recursion
    }
}
```



