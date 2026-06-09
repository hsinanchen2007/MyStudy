### 解题思路
巧妙使用异或运算，进行矩阵翻转

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        if(matrix==null|| matrix.length<=1){
            return;
        }
        //循环层数
        int length=matrix.length;
        int swl=length-1;
        int count=length;
        for(int i=0;i<length/2;i++){
            //交换
            count--;
            for(int j=i;j<count;j++){
                matrix[i][j]=matrix[i][j]^matrix[j][swl-i]^matrix[swl-i][swl-j]^matrix[swl-j][i];
                matrix[j][swl-i]=matrix[i][j]^matrix[j][swl-i]^matrix[swl-i][swl-j]^matrix[swl-j][i];
                matrix[swl-i][swl-j]=matrix[i][j]^matrix[j][swl-i]^matrix[swl-i][swl-j]^matrix[swl-j][i];
                matrix[swl-j][i]=matrix[i][j]^matrix[j][swl-i]^matrix[swl-i][swl-j]^matrix[swl-j][i];
                matrix[i][j]=matrix[i][j]^matrix[j][swl-i]^matrix[swl-i][swl-j]^matrix[swl-j][i];
            }
        }
    }
}
```