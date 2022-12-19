### 解题思路
看注释

### 代码

```java
class Solution {
    public int maxScoreSightseeingPair(int[] A) {
        //找最大，两个for搞定拉，应该能优化什么
        //考虑复杂度，5e4 + (5e4 - 1) + (5e4 - 2)。。。。。等差数列 d=-1
        //Sn = na1 + d * n*(n-1) / 2
        //所以复杂度是5e4*5e4 - 5e4*(5e4 - 1)/2 = 25e8 - 10e8 - 2e4 = 15e8   超1s
        
//         int len = A.length;
//         int MAX = Integer.MIN_VALUE;
//         for (int i = 0; i < len; ++i) {
//             for (int j = i + 1; j < len; ++j) {
//                 int tmp = A[i] + A[j] + i - j;
//                 if (tmp > MAX)
//                     MAX = tmp;
                    
//             }
//         }
//         return MAX;
        
         //你要max,那加得最大,减得最小,sort一遍,明显下标就变了 不行
        //可以发现A[j] 和 A[i]这些绑定着j i 就是配套不变的
        //扫一遍 一遍扫 一遍记录最大MAXI 再一直求ans
        int len = A.length;
        //至少两长度
        int MAXI = A[0] + 0;
        int ans = Integer.MIN_VALUE;
        for (int j = 1; j < len; ++j) {
            int tmp = A[j] - j;
            if (MAXI + tmp > ans) ans = MAXI + tmp;
            if (A[j] + j > MAXI) MAXI = A[j] + j;
        }
        return ans;
    }
}
```