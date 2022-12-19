### 题目解释，读懂题才能做的下去
indices = [[0,1],[1,1]] 中0，1，1，1的意思是：
1. 将矩阵中0行的值都加1 
2. 将矩阵中1列的值都加1
3. 将矩阵中1行的值都加1 
4. 将矩阵中1列的值都加1 
依次类推

通过indices数组的这么一顿折腾，最后问矩阵中有多少个奇数

### 解题思路

### 代码

```java
class Solution {
    public int oddCells(int n, int m, int[][] indices) {
        //行： 下标是行号,值是行中1的数量
        int[] h = new int[n];
        //列： 下标是列号,值是列中1的数量
        
        int[] v = new int[m];
        for(int i=0; i< indices.length; i++) {
            int row = indices[i][0]; // 这一行都是1
            int col = indices[i][1]; // 这一列都是1
            h[row]++;
            v[col]++;
        }

        int count = 0;
        for(int i=0; i < n; i++) {
            for(int j=0; j<m ;j++) {
                 if(((h[i]  + v[j]) & 1) == 1){
                    count++;
                 }
            }
        }
        return count;
    }
}
```