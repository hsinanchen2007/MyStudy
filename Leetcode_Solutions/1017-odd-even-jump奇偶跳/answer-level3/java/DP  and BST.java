DP用来存每个数组index处当前步数奇数/偶数的情况下能不能到达目的地
最后一个数字当然可以，从右往左扫码，当前数字的下一步如果可以就可以

BST(<code>TreeSet<code>)用来辅助找比当前位置大于等于或小于等于关系的最近数组index
考虑到不管找大找小都是较小index优先，我用了两个BST

```
class Solution {
    /************************************
      Do not forget values not distinct
      
      Time: 1. BST   O(log n) * n = O(n log n)
            2. DP    O(n)
            O(n log n) in total
            
      Space 1. BST  O(n)
            2. DP   O(n)
            O(n) in total
    ***************************************/
    
    public int oddEvenJumps(int[] A) {
        int n = A.length;
        if (n == 1) return 1;
        
        int[][] dp = new int[n+1][2];
        
        dp[n][0] = 1;
        dp[n][1] = 1;
        
        int[] greater = new int[n+1];
        int[] smaller = new int[n+1];
        
        TreeSet<Integer> bst1 = new TreeSet<>((a, b) -> A[a] - A[b]
                                             != 0 ? A[a] - A[b] : a - b
                                             );
        TreeSet<Integer> bst2 = new TreeSet<>((a, b) -> A[a] - A[b]
                                             != 0 ? A[a] - A[b] : b - a
                                             );
        
        for (int i = n-1; i >= 0; i--) {
            if (i == n-1) {
                greater[i+1] = -1;
                smaller[i+1] = -1;
            } else {
                greater[i+1] = java.util.Optional.ofNullable(bst1.ceiling(i)).orElse(-1);
                smaller[i+1] = java.util.Optional.ofNullable(bst2.floor(i)).orElse(-1);
            }
            
            bst1.add(i);
            bst2.add(i);
        }
        
        for (int i = n-1; i > 0; i--) {
            if (smaller[i] == -1) {
                dp[i][0] = -1;
            } else {
                dp[i][0] = dp[smaller[i] + 1][1];
            }
            
            if (greater[i] == -1) {
                dp[i][1] = -1;
            } else {
                dp[i][1] = dp[greater[i] + 1][0];
            }
        }
        
        return (int)Arrays.stream(dp).filter(arr -> arr[1] == 1).count();
    }
}
```
