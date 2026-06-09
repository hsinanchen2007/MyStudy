### 解题思路
写一下我出错的几点：
1.判断矩阵为空一定要放到第一步（别问我为什么）
2.一定要搞清楚遍历之后少的是right和down还是增加了left和up
3.代码里的注释写的很清楚了看一遍就应该懂了

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrixSize==0||matrix==NULL)
    {
        * returnSize=0;
        return 0;
    }//空矩阵返回
    int index=0,i=0;//建立新数组元素及遍历元素
    int up=0,down=matrixSize-1;//设立上下两个监控值
    int left=0,right=matrixColSize[0]-1;//设立左右两个值
    int *res=(int*)malloc(sizeof(int)*(matrixSize*matrixColSize[0]));//开辟新数组
    int count=0;//新数组长度
    while(up<=down&&left<=right)
    {
        for(i=left;i<=right;i++)
        {
            count++;
            res[index++]=matrix[up][i];
        }//从左到右遍历存入新数组
        up++;
        if(up>down)break;//上行减一判断是否有空行
        for(i=up;i<=down;i++)
        {
            count++;
            res[index++]=matrix[i][right];
        }//从上到下遍历存入数组
        right--;
        if(left>right)break;//右列减一判断是否有空列
        for(i=right;i>=left;i--)
        {
            count++;
            res[index++]=matrix[down][i];
        }//从右到左遍历存入数组
        down--;
        if(up>down)break;//下行减一判断是否有空行
        for(i=down;i>=up;i--)
        {
            count++;
            res[index++]=matrix[i][left];
        }//从下到上遍历存入数组
        left++;
        if(left>right)break;//左列加一判断是否有空列
    }
    * returnSize=count;
    return res;

}
```