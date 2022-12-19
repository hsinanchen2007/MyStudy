和上周周赛题有点相似，可以参看[传送门：统计全为 1 的正方形子矩阵](https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones/)里我的解答。

遍历每一个位置ij时，将该位的数值置为从该位起左边的1的总个数，例如对于矩阵
```
  [1,1,3,2],
  [1,1,4,3],
  [1,2,4,2]
```
遍历结束后效果为：
```
  [1,2,5,7],
  [1,2,6,9],
  [1,3,7,9]
```
为了统计正方形矩阵的面积，可以假定当前位置ij为正方形的右下角点，这个正方形可能的最大边长为maxlen = Math.min(i, j) + 1。

沿着同一列j向上遍历，遍历行数即为当前正方形的边长len，利用前缀和可以求得当前正方形的每一行的面积rowarea。
```
rowarea = mat[row][j] - mat[row][j - len];
```
再将所有行面积遍历加和即可得到正方形的面积。取满足面积要求的最大边长即可。

```java
public int maxSideLength(int[][] mat, int threshold) {
    int result = 0;
    for(int i = 0; i < mat.length; i++) {
        for(int j = 0; j < mat[0].length; j++) {
            if(j != 0){
                mat[i][j] += mat[i][j - 1];
            }
            int len = 0;
            int maxlen = Math.min(i, j) + 1;
            while(len < maxlen){
                int area = 0;
                for(int k = 0; k < len + 1; k++) {
                    int prefix = j - len - 1 < 0 ? 0 : mat[i - k][j - len - 1];
                    area += mat[i - k][j] - prefix;
                }
                if(area > threshold){
                    break;
                }
                len++;
            }
            result = len > result ? len : result;
        }
    }
    return result;
}
```

欢迎与我交流~

[LeetCode 从零单刷个人笔记整理（持续更新）](https://blog.csdn.net/qq_20304723/article/details/89401203)

github：[https://github.com/ChopinXBP/LeetCode-Babel](https://github.com/ChopinXBP/LeetCode-Babel)