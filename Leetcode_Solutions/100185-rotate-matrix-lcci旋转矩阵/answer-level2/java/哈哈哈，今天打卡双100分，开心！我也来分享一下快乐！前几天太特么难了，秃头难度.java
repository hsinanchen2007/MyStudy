### 解题思路
鉴于本人数学不好，就知道矩阵转置，So我观察了一下，转置后在把每行首尾元素不断交换就可以！
（1）暴力转置会需要开辟一个新矩阵，矩阵转置的特征告诉我，主对角线元素不用动弹，只用动上三角或者下三角！
（2）暴力交换不好，借鉴一下快排的双指针他不香吗？哈哈哈

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        if(matrix==null) return;//空矩阵
        int row=matrix.length;
        int col=matrix[0].length;
        if(row==1 && col==1) return;//一维矩阵

        //the Transpose of the Matrix
        int temp=0;       
        for(int i=0;i<row;i++){
            for(int j=i+1;j<col;j++){
                temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        
        for(int i=0;i<row;i++){
            int l=0;//定义两个指针一头一尾
            int h=col-1;
            while(l<h){
                temp=matrix[i][l];
                matrix[i][l]= matrix[i][h];
                matrix[i][h]=temp;
                l++;
                h--;
            }
        }
    }
}
```