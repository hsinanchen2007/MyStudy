### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int []result = new int[matrix.length *matrix.length];
        int index = 0;
        for(int i=0; i<matrix.length; i++){
            for(int j=0; j<matrix.length; j++){
                result[index] = matrix[i][j];
                index++;
           }
        }
        Arrays.sort(result);
        return  result[k-1];
    }
}
```