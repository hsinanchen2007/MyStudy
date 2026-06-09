别人给的题解我理解了，but 我的为什么错误我一直没有明白： 这道题是不是可以转化为：排列组合问题。 比如一共有7节楼梯 1： 3个2，1个1： 求有多少种排列=C4<sup>1</sup>    
2： 2个2, 3个1： 求有多少种排列= C5<sup>2</sup>    
3. 1个2， 5个1 求有多少种排列= C6<sup>1</sup>    
4. 0 个2， 7个1. 求有多少种排列= C7<sup>0</sup>     
故总数为： 4+10+6+1 =21


```
class Solution {
   public int climbStairs(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }

        int once = n % 2;
        long twice = n / 2;
        long sum = 1;
        if (once == 1) {
            sum = twice + 1;
        }

        for (long i = twice-1; i > 0; i--) {
            once += 2;
            // i+1 代表有多少个位置可以插入。
            sum += unsortComputeCombine(once, i);
        }
        return (int) sum + 1;
    }


    private long unsortComputeCombine(long a, long b) {
        if (a == 0 || b == 0) {
            return 1;
        } else if (a == 1) {
            return b + 1;
        } else if (b == 1) {
            return a + 1;
        }

        return a >= b ? computeCombine(a, b) : computeCombine(b, a);
    }      

    private long computeCombine(long small, long large) {
        long divided = 1;
        long divisor = 1;
        for (long i = 1; i <= small; i++) {
            divided = divided * (large + i);
            divisor = divisor * i;
        }
        return divided / divisor;
    }
}
```