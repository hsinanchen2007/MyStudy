**方法一：代码实现类似斐波那契数列**
```
class Solution {
    /**
    * 思路：
    * (1) 由题可知每次可爬1或2个台阶，爬1阶有1种方法，爬2阶有两种方法，
    *       爬3阶的方法为爬1阶的方法爬2个台阶或者爬2阶的方法爬1个台阶；
    * (2) 所以爬3阶的方法数为爬1阶和爬2阶的方法数之和，爬n阶的方法数为f(n-2)+f(n-1)，
    *       类似斐波那契数列除了开始两位数，每位数都等于前两位数之和。
    */
    public int climbStairs(int n) {
        if(n <= 1){
            return 1;
        }else if(n == 2){
            return 2;
        }
        // 从第3阶开始循环，直至爬到n阶
        int temp = 0;
        int a = 1, b = 2;
        int c = 3;
        while(c <= n){
            temp = a + b;
            a = b;
            b = temp;
            c++;
        }
        return temp;
    }
}
```


**方法二：带入斐波那契数列公式**
![fbnq.jpg](https://pic.leetcode-cn.com/da856c2b220e5491aa21c259da34543bfd892fc710835967c1681d9b099a300b-fbnq.jpg)
```
public class Solution {
    /**
    * 思路：
    * 由题知道是类似斐波那契数列，因为第一位是1，第二位是2，带入斐波那契数列从(n+1)位算起
    */
    public int climbStairs(int n) {
        double sqrt5=Math.sqrt(5);
        double fibn=Math.pow((1+sqrt5)/2,n+1)-Math.pow((1-sqrt5)/2,n+1);
        return (int)(fibn/sqrt5);
    }
}
```