### 解题思路
前缀和O(mn) 8ms
思路都在注释里 不懂的加群 812791932 问二哥狗哥泡菜哥
### 代码

```java
class Solution {
  public int maxSideLength(int[][] mat, int threshold) {
    // 构造二维前缀和 
    int[][] S = new int[mat.length + 1][mat[0].length + 1];
    int maxLen = 0;
    for(int r = 1; r < S.length; r++){
      for(int c = 1; c < S[0].length; c++){
        //构造
        S[r][c] = S[r - 1][c] + S[r][c - 1] + mat[r - 1][c - 1] - S[r - 1][c - 1];
        // 判断是否有该点为右下角定点的更大的正方形，sum <= threshold, 如果有 更新最大边。
        int maxPossibleLen = Math.min(r, c) ;
        for(int k = maxLen + 1; k <= maxPossibleLen; k++){
          int x1 = r - k + 1;
          int y1 = c - k + 1;
          int subSum = S[r][c] - S[r][y1 - 1] - S[x1 - 1][c] + S[x1 - 1][y1 - 1];
          if(subSum <= threshold){
            // System.out.println(x1 +" " + y1 + " " + i + " " + j +" " + minLen);
            maxLen = k;
          }else{ // 因为都是正的 所以一旦发现不行就直接Break
            break;
          }
        }
      }
    }
    return maxLen;
  }
}
```