### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int []num=new int[matrix.length*matrix.length];
        int x=0;
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix.length;j++){
                num[x++]=matrix[i][j];
            }
        }
        Arrays.sort(num);
        return num[k-1];
    }
}
```