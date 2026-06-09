# 画图解法

![矩阵旋转.jpg](https://pic.leetcode-cn.com/318a7ff8b43991d539de6786dafa5b044f0a2f90f8ab9afce11fffae0056874b-%E7%9F%A9%E9%98%B5%E6%97%8B%E8%BD%AC.jpg)
解法如上图所示，只需要循环红色三角形里面的数字即可，每次交换四个数字的值，他们依次是  
```
matrix[i][j]
matrix[j][n-1-i]
matrix[n-1-i][n-1-j]
matrix[n-1-j][i]
```
我的代码如下：
```java
class Solution {
    public void rotate(int[][] matrix) {
        if(matrix!=null&&matrix.length>1)//如果方阵matrix不为空和边长大于1
        {
            int n=matrix.length,count_row=0;//n是边长，count_row计数到了哪一行（需要用到）
            for(int i=0;i<n/2;i++)//循环
            {
                for(int j=i;j<n-1-count_row;j++)//循环
                {
                    rotate_four_points(matrix,n,i,j);//交换四个数的值
                }
                count_row++;//对j的范围有影响
            }
        }      
    }

    private void rotate_four_points(int[][] matrix,int n,int i,int j)
    {
        int a=matrix[i][j],b=matrix[j][n-1-i];//临时变量
        int c=matrix[n-1-i][n-1-j],d=matrix[n-1-j][i];//临时变量
        matrix[i][j]=d;//交换值
        matrix[j][n-1-i]=a;//交换值
        matrix[n-1-i][n-1-j]=b;//交换值
        matrix[n-1-j][i]=c;//交换值
    }
}
```
