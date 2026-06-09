### 解题思路

迭代优化改写：将结果存在变量ans（最后剩下的数位置下标，最后只有3 下标是0）里面 每次叠加ans即： ans = (ans + m) % i
最后只剩下1个数 执行没有意义 所以从只剩下2个数开始 倒推（dp迭代解法）
先计算f(2,m) 在计算f(3,m)... 直到f(n,m)

### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        
        //return deleteList(n,m);
        return deleteByMathSolution(n,m);
    }
    /*
    * 数学方法 O(n)
    *
    * 1. 首先定义n个数围成的圈每次删除第m个数剩下的数为方程f(n, m)。在n个数中，第一个被删除的数是(m-1)%n。
    * 记(m-1)%n = k，则删除k后剩下的n-1个数分别为: 0,1,...,k-1,k+1,...,n-1，下次删除从k+1开始计数。
    * 相当于从k+1重排剩下的数为: k+1,...,n-1,0,1,...,k-1。
    * 2. 再定义删除了k的重排序列的方程为f'(n-1, m)，因为它们都表示最终剩下的数，所以f(n, m) = f'(n-1, m)。
    * 3. 将f'(n-1, m)的重排序列映射为f(n, m)的形式：
    *    k+1 -> 0,  k+2 -> 1, ... n-1 -> n-k-2, 0 -> n-k-1, 1 -> n-k, ... k-1 -> n-2
    * 将映射定义为:
    *    p(x) = (x-k-1)%n，
    * 则逆映射为:
    *    p-1(x) = (x+k+1)%n。
    * 由于映射后的序列和最初的序列形式相同，仍然使用f(n-1, m)表示。映射之前的序列中最后剩下的数字:
    *    f'(n-1, m) = p-1(f(n-1, m)) = (f(n-1, m)+k+1)%n
    * 将k = (m-1)%n代入上述方程：
    *    f(n, m) = f'(n-1, m) = (f(n-1, m) + (m-1)%n+1)%n = (f(n-1, m) + m)%n。
    *
    * 所以综上所述，可以总结递推公式为：
    *    1> 当n=1时，f(n, m) = 0;
    *    2> 当n>1时，f(n, m) = (f(n-1, m) + m)%n
    * 迭代优化改写是：将结果存在变量ans里面 每次叠加ans即： ans = (ans + m) % i
    * 最后只剩下1个数 执行没有意义 所以从只剩下2个数开始 倒推（dp迭代解法）
    * 先计算f(2,m) 在计算f(3,m)... 直到f(n,m)
    * */
    private int deleteByMathSolution(int n, int m){
        if (n < 1 || m < 1) {
            return -1;
        }

        int ans = 0;
        // 根据数学递推的方式获得计算公式 
        for (int i = 2; i <= n; i++) {
            ans = (ans + m) % i;
        }

        return ans;
    }
    /**1141ms too long
    **@params n
    **@params m
    **deletePos 每一轮删除位置 也是下一次删除开始计数位置
    **/
    private int deleteList(int n, int m){
        List<Integer> list=new ArrayList<>();
        for(int i=0;i<n;i++){
            list.add(i);
        }
        //delete 
        int tn=n;
        int deletePos=0;//
        for(int i=0;i<n-1;i++){
            deletePos=(m-1+deletePos)%tn;
            list.remove(deletePos);
            tn--;
        }
        
        return list.get(0);
    }
}
```