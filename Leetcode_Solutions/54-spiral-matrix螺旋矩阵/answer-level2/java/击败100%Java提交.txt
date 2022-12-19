### 解题思路
按照螺旋的方式遍历数组，可以将这个过程分为两个部分：1. 按照层数遍历 2. 遍历最内层的行或者列。
每层的遍历可以分为四个部分：上、右、下、左，按照这个顺序可以遍历厚度d为1的序列。
另外，在数组的最内层可能会有一行或者一列还没遍历，经过分析发现：
* 如果剩下的是一行，那么一定满足条件列数>行数，且行数为奇数
* 如果剩下的是一列，那么一定满足条件行数>列数，切列数为奇数
* 按照这个思路即可写出数组的螺旋遍历

### 代码

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        if(matrix.length==0){
            return new ArrayList();
        }
        int m = matrix.length;
        int n = matrix[0].length;
        List<Integer> res = new ArrayList();
        int d = Math.min(m/2,n/2);
        for(int i = 0;i<d;i++){
            for(int j = i;j<n-i-1;j++){
                res.add(matrix[i][j]);
            }
            for(int j = i;j<m-i-1;j++){
                res.add(matrix[j][n-i-1]);
            }
            for(int j=n-i-1;j>i;j--){
                res.add(matrix[m-i-1][j]);
            }
            for(int j=m-i-1;j>i;j--){
                res.add(matrix[j][i]);
            }
        }
        if(m%2==1 && n>=m){
            int r = (m+1)/2-1;
            for(int i = r;i<n-d;i++){
                res.add(matrix[r][i]);
            }
        }
        if(n%2==1 && m>n){
            int c = (n+1)/2-1;
            for(int j=c;j<m-d;j++){
                res.add(matrix[j][c]);
            }
        }
        
        return res;
    }
}
```