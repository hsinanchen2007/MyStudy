### 解题思路
旋转前的一行的值对应的索引 00，01，02
旋转后的一行的值对应的索引 20，10，00

旋转前的二行的值对应的索引 10，11，12
旋转后的二行的值对应的索引 21，11，01

每行改变后的值对应的索引是改变前的值对应的索引的镜像

此方法仅适用于N x N的矩阵。

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        if(matrix == null){return;}
        int n = matrix.length;
        List<Integer> array = new ArrayList<>(2*n);
        for(int i = 0; i < n; i++){
            for(int j = n-1; j >= 0; j--){
                array.add(matrix[j][i]);
            }
        }

        int m = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = array.get(m++);
            }
        }
    }
}
```