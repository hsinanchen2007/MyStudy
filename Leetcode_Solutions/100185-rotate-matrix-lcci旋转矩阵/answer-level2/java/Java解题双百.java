### 解题思路
![image.png](https://pic.leetcode-cn.com/3627ed387f93920203931bc61d9f0e69acec7a3efef7a359a4ae4e5624ff2488-image.png)
1、将数组进行转置
2、将数组的每一行折半交换
### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < i; j++){
                if(i != j){
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
        }
        for(int[] array : matrix){
            int i = 0,j = n - 1;
            while(i<j){
                int temp = array[i];
                array[i++] = array[j];
                array[j--] = temp;
            }
        }
    }
}
```