### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] transpose(int[][] A) {
  int len1=A.length;
         int len2=A[0].length;
         int res[][]=new int[len2][len1];
         for(int i=0;i<len2;i++){
             for(int k=0;k<len1;k++){
                 res[i][k]=A[k][i];
             }
         }
         return res;
    }
}
```