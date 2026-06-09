### 解题思路

![图片.png](https://pic.leetcode-cn.com/236867072140b57a03e6a68b8315416dc7780d904ca00ae583d3ea529200dbe4-%E5%9B%BE%E7%89%87.png)

想了很久，最后还是选择参考评论里的大神hhhhhh
大致思路：从右上角开始查找，如果target>该数则删除行，target<该数则删除列
具体见代码↓↓


### 代码

```c
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
    
    
    if(matrixSize==0)
    return false;
    
    int col=*matrixColSize;
    int row=matrixSize;
    int counter1=1;//计数器，标记删除了几列


    for(int i=0;i<row;i++)//行循环
    {

        for(int j=col-counter1;j>=0;j--)//列循环
        {
            if(matrix[i][j]>target)//删除列
                counter1++;
            else if(matrix[i][j]<target)//删除行
                break;
            else return true;

        }
    }

    return false;

}
```