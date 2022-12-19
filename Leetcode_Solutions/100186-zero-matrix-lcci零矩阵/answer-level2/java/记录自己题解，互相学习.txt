### 解题思路
附加两个数组来分别记录出现零的行或者列，然后遍历整个二维数组，设置存在零的行和列的元素为零。时间复杂度为O(MN)，属于基本思想

### 代码

java
class Solution {
    public void setZeroes(int[][] matrix) {
        int line=matrix.length;//行
        int row=matrix[0].length;//列
        int[] a=new int[line];//记录存在零的行
        int[] b=new int[row];//记录存在零的列

        for(int i=0;i<line;i++){//初始化行
            a[i]=0;
        }
         for(int j=0;j<row;j++){//初始化列
            b[j]=0;
        }
        for(int i=0;i<line;i++){//记录零所在的行和列
            for(int j=0;j<row;j++){
                if(matrix[i][j]==0){
                    a[i]=1;
                    b[j]=1;
                }
            }
        }
        //消除存在零的行和列设置为零
        for(int i=0;i<line;i++){
                for(int j=0;j<row;j++){
                       if(a[i]==1||b[j]==1){
                           matrix[i][j]=0;
                        }
                }

        }
        
    }

}
```