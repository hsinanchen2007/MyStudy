
这道题常规思路都会想到二分法，然而，并不是这样的。

我们再理下题意，我们如何在最坏情况下花最少的钱。
**最坏的情况就是，** 如果我在1~n中猜到i了，那么此刻，你有两种方向的走势，即i的左右两边的集合。结果，你就是这样倒霉，最终值在较长的集合里，于是你在这个最长集合里选了一个值j，结果继续不幸的是最终值又在j的左右两边集合的最长集合里，总之，你就是很倒霉的命中最长的集合，**导致你猜的次数非常多，求最大值**。
**如何花钱少？** 那么在这些艰难中，哪种艰难付出代价最小呢。譬如n=2，你肯定猜1，不会猜2，所以，倒霉是倒霉，但不意味着你脑子笨。-->**求最小值**。

现在人为创造艰难，从1开始，然后继续在它的左右两个集合里选择最长的路（子问题）去走，因为每次猜的i要算作你这次付出的代价，所以，每次计算记得加上这个i。
Math.**max**(processing(i+1,n)/**这是i的右边集合**/,processing(start,i-1)/**这是i的左边集合**/)/**选择猜测次数最多（max）的路**/ + i。所以，我们遍历艰难，然后求代价最小的值。
```
for(int i=start;i<n;i++){
            ans = Math.min(ans,Math.max(processing(i+1,n,mem),processing(start,i-1,mem))+i);
}
```
我们发现每次左右两个集合的遍历，都会被划分成子问题，到最后可能会变成，只有2个数的情况，就像我刚说的，如果n=2，你肯定付出1块，去猜，而不是花2块，所以，这个问题的终结就变成如果子问题变成了2个数，那么return n-1。
然后我们加上递归伴侣，mem数组，记录每次已经计算过的值，这样不用重复计算，直接返回。

```
public class Solution {
    public int getMoneyAmount(int n) {
        int[][] mem = new int[n+1][n+1];
        return processing(1,n,mem);
    }
    public int processing(int start, int n,int[][] mem){
        if(mem[start][n]!=0){
            return mem[start][n];
        }
        if(n==1||n==0){
            return 0;
        }
        if(n-start==1){
            return n-1;
        }
        if(start>=n){
            return 0;
        }
        int ans = Integer.MAX_VALUE;
        for(int i=start;i<n;i++){
            ans = Math.min(ans,Math.max(processing(i+1,n,mem),processing(start,i-1,mem))+i);
        }
        mem[start][n] = ans;
        return ans;
    }
}
```