### 解题思路
此处撰写解题思路

### 代码

```java
public class Solution70 {
    public int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
    //这是一个斐波那契数列，爬n个的方法数，等于怕n-1和n-2个的方法数之和。（分两种情况 最后一次爬1个，最后一次爬2个）
    //但是这种方法时间复杂度特别大，因为会重复计算。例如，算f5 = f4 + f3时已经有了f5，可是计算f6是又会再次来计算f5
    //其时间复杂度为2^n，相当于一个二叉树
    //一种优化方法就是，用数组去储存已经计算出来的结果
    public int climbStairs2(int n) {
        int[] sum = new  int[n + 1];
        sum[1] = 1;
        if(n == 1) 
            return sum[1];
        sum[2] = 2;
        if(n == 2) 
            return sum[2];
        for(int i = 3 ; i < n+1 ; i ++)
            sum[i] = sum[i - 1] + sum[i - 2];
        return sum[n];
    }
    //递归是从上往下，这个是从下往上
    
    //同样可以用最简单的for循环来写斐波那契数列，跟上述思路大致相同
    public int climbStairs3(int n) {
        if(n == 1) 
            return 1;
        if(n == 2) 
            return 2;
        int x = 1, y = 2, sum = 0;
        for(int i = 3 ; i < n + 1 ; i ++){
            sum = x + y;
            x = y;
            y = sum;
        }
        return sum;
    }
    
    public static void main(String[] args){
        Solution70 s = new Solution70();
        System.out.println(s.climbStairs3(5));
    }
}
```