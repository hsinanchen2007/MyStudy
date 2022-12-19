根据总阶数和两种上楼方式易得两种步长的数量关系，即 one + 2 * two = n。

根据组合数公式，两种步长相同时共有Combination(t, t + o)种可能。对于组合数的运算，阶乘会导致计算结果过大，超出LONG范围，使用Int除法或者Double除法都将导致精度损失，因此使用边乘边除的方式，当无法整除时先等待，直到可以整除的时候再整除。

题解会在n参考范围为1-45，在该范围可得到正确结果。

```
class Solution {
    public int climbStairs(int n) {
        int res = 0;

        for(int t = 0; t <= n/2; t++){
            int o = n - 2 * t;
            res += doCombination(t, t + o);
 
        }
        return res;
    }


    public int doCombination(int a, int b){
        long result = 1;
        int j = 1;
        for(int i = a+1;i <= b; i++){
            result *= i;
            if(result%j == 0){
                result /= j;
                j++;
            }
        }
        System.out.println(result);
        for(;j <= b-a; j++){
            result /= j;
        }

        return (int)result;
    }

}
```
