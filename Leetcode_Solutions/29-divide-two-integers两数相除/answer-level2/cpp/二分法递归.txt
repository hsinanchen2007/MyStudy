### 解题思路
参考
https://leetcode-cn.com/problems/divide-two-integers/solution/po-su-de-xiang-fa-mei-you-wei-yun-suan-mei-you-yi-/
核心地方在于二分法求商，以及对除数是-1、1的边界判断。
### 代码

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        // 递归解法 若相等 sum++ 返回sum
        // 小于 返回0；
        // 大于 查看翻倍后是
        if(dividend==0) return 0;
        bool flag = false; // 同号
        if((dividend<0&&divisor<0)||(dividend>0&&divisor>0)) flag = true;
        // 全部变为正
        long a = dividend;
        long b = divisor;
        if(a<0) a = -a;
        if(b<0) b = -b;
        if(b==1){
            if(flag){
                if(a<=INT_MAX) return a;
                return INT_MAX;
            } 
            else return -a;
        }
        int res = div(a,b);
        if(flag) return res;
        return -res;
    }
    long int div(long int dividend,long int divisor){
        // 两个正数的除法
        if(dividend<divisor) return 0;
        long int count = 1; // 从1开始
        long int curDivisor = divisor;
        while((curDivisor+curDivisor)<=dividend){
            // 当前解可接受
            count = count + count; 
            curDivisor = curDivisor + curDivisor;
        }
        return count + div(dividend-curDivisor,divisor);
    }
};
```