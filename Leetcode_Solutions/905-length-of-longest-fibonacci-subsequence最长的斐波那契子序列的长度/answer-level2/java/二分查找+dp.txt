#### [873. 最长的斐波那契子序列的长度](https://leetcode-cn.com/problems/length-of-longest-fibonacci-subsequence/)

如果序列 X_1, X_2, ..., X_n 满足下列条件，就说它是 斐波那契式 的：

```latex
n >= 3, 对于所有 i + 2 <= n，都有 X_i + X_{i+1} = X_{i+2}
```

给定一个严格递增的正整数数组形成序列，找到 A 中最长的斐波那契式的子序列的长度。如果一个不存在，返回  0 。（回想一下，子序列是从原序列 A 中派生出来的，它从 A 中删掉任意数量的元素（也可以不删），而不改变其余元素的顺序。例如， [3, 5, 8] 是 [3, 4, 5, 6, 7, 8] 的一个子序列）

```java
示例 1：
输入: [1,2,3,4,5,6,7,8]
输出: 5
解释:
最长的斐波那契式子序列为：[1,2,3,5,8] 。

示例 2：
输入: [1,3,7,11,12,14,18]
输出: 3
解释:
最长的斐波那契式子序列有：
[1,11,12]，[3,11,14] 以及 [7,11,18] 。

提示：3 <= A.length <= 1000
1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9
```

#### 思路

使用动态规划来解决这个问题的特征比较明显，dp[i]\[j]表示序列从j项到i项构成的斐波那契序列的长度，的最长斐波那契子序列的长度，转移方程：

dp[j]\[k] = Math.max(dp[j]\[k], d[i]\[j]+1 if(k,i,j可以形成新的斐波那契序列)。

子问题：如何判断第i项和第j项能够形成新的斐波那契序列呢？

```java
public int methodOne(int[] A){
        int n = A.length;
        int[][] dp = new int[n][n];
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                dp[i][j] = 2;
            }
        }
        int ans = 0;
        for(int k=2; k<n; k++){
            for(int j=1; j<k; j++){
                //在[0:j-1]区间内，寻找A[k]-A[j]的位置i
                int i = findIdx(A, 0, j-1, A[k]-A[j]);
                if(i!=-1){
                    dp[j][k] = Math.max(dp[j][k], dp[i][j]+1);
                    ans = Math.max(ans, dp[j][k]);
                }
            }
        }

        return ans>2?ans:0;
    }

	//使用二分法优化查找
    public int findIdx(int[] A, int start, int end, int target){
        int left = 0, right=end;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(A[mid]>target) right = mid-1;
            else if(A[mid]==target) return mid;
            else left = mid+1;
        }
        return -1;
    }
```



