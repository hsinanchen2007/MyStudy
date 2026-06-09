```
class Solution {
    public int climbStairs(int n) {
        /*
        思路：
        首先想思路，动态规划的问题就是第n个结果和前一个前两个或者前三个都有什么关系
        能够总结出状态转移方程。
        这个问题就是 上第n阶台阶可以由第n-1阶上去也可以由第n-2阶上去。
        即 f(n) = f(n-1) + f(n-2) ;就是一个斐波那契数列的问题。
        */


        /*
        解法1：
        第一种递归的解法，在n=45时超时。
        if(n<=2){
            return n ;
        }
        return climbStairs(n-1)+climbStairs(n-2) ;
        */

        //解法二：
        //雙一百的解法。
        if(n<=2){
            return n ;
        }
        int preTwo = 1 ;
        int preOne = 2 ;
        int result = 0 ;
        //注意下邊界條件是小於等於。
        for(int i=3;i<=n;i++){
            //f(n) = f(n-1)+f(n-2)
            result = preOne+preTwo ;
            preTwo = preOne ;
            preOne = result ; 
        }
        return result ;    
    }
}
```
