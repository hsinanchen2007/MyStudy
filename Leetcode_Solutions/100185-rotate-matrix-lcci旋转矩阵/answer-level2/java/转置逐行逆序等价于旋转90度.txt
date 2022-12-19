### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/701ca8c4f6927cda9c116db11427233179d7e82945e4fa9541ef1fcfd1dc1fd2-image.png)

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<i;j++){
                int top=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=top;
            }
        }
        for(int i=0;i<matrix.length;i++){
            for(int j=0,k=matrix[0].length-1;j<k;j++,k--){
                int top=matrix[i][j];
                matrix[i][j]=matrix[i][k];
                matrix[i][k]=top;
            }
        }
    }
}
```