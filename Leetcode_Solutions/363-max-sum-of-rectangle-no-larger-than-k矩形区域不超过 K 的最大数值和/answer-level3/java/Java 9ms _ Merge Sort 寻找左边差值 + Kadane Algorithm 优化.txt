### 解题思路
1. 选择矩形的第一列为i，最后一列为j，那么剩下的问题就是寻找从第几行到第几行组成的矩形和最大。
    关于利用前缀和、滚动数组压缩，把求矩形和转换成一维数组最大子数组和，不懂的话可以看[这道题](https://leetcode-cn.com/problems/number-of-submatrices-that-sum-to-target/submissions/)

2. 此题利用了 Merge Sort 过程 left 与 right 相对有序的性质，来寻找某个位置左边第一个比 Target 小的最大值，用TreeMap(BST) 一样可以。

3. 在寻找「头在i，尾在j」的最大矩形时，使用 Kadane Algorithm 先求出这一列所有子数组的最大值。超过 K 才去搜索所有组合。
    不懂 Kadane Algorithm 算法可以看[这里](https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/solution/6xing-dai-ma-1ms-3xing-jie-shi-by-18716060157/)


### 代码

```java
class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        if(matrix == null || matrix.length == 0) {
            return -1;
        }
        int m = matrix.length, n = matrix[0].length;
        int[] sums = new int[m + 1];
        int ans = Integer.MIN_VALUE;
        int i, j, s;
        
        for(i = 0; i < n; i++) {
            int[] A = new int[m]; // 易错点: A 从 i 固定开始是一个新的
            for(j = i; j < n; j++) {
                int max = Integer.MIN_VALUE, sub = 0;
                for(s = 0; s < m; s++) {
                    A[s] += matrix[s][j];
                    sums[s + 1] = sums[s] + A[s];
                    // Kadane Algo maximum subarray sum
                    sub = Math.max(sub + A[s], A[s]);
                    max = Math.max(max, sub);
                }
                if(max <= k) { // 子数组最大和大于 k 才去搜寻所有组合
                    ans = Math.max(ans, max);    
                }else {
                    ans = Math.max(ans, mergeSort(sums, 0, m, k));
                }
            }
        }
        return ans;
    }
    
    private int mergeSort(int[] sum, int start, int end, int k) {
        if(start >= end) { 
            return Integer.MIN_VALUE;
        }
        int mid = start + (end - start) / 2;
        int ans = mergeSort(sum, start, mid, k); // 易错点，这里用 mid - 1，当start,end 相邻时，right[mid,end] 会爆栈
        if(ans == k) {
            return ans;
        }
        ans = Math.max(ans, mergeSort(sum, mid + 1, end, k)); 
        if(ans == k) {
            return ans;
        }
        
        int[] temp = new int[end - start + 1];
        int i, j = mid + 1, t = 0;
        int p = mid + 1;
        for(i = start; i <= mid; i++) {
            while(p <= end && sum[p] - sum[i] <= k) {
                ans = Math.max(ans, sum[p] - sum[i]);
                p++;
            }
            while(j <= end && sum[j] < sum[i]) temp[t++] = sum[j++];
            temp[t++] = sum[i];
        }
        System.arraycopy(temp, 0, sum, start, t);
        return ans;
    }
}
```