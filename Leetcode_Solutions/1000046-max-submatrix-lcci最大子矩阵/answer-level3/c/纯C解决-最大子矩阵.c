### 解题思路
这道题的本质来源于最长公共连续子序列和，好好的手动模拟一遍我的代码，你就用这个数组，你就可以明白了。

 0 -2 -7   0
 9  2  16  2
-4 1  -4   1
-1 8   0  -2

答案就是
 9 2 
-4 1 
-1 8
这里说明以下mark数组的用法，mark[i][j]这里保存的是从0行到i行的j列位置的元素之和。

arr[]辅助数组就是用来求最长连续子序列和
这里需要好好的品读一下：mark[j][k]-mark[i-1][k];

如有疑问，欢迎留言~
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int CountMax(int *arr,int length,int *c1,int *c2)//最大连续子序列和
 {
     int dp[length];//辅助数组
     int i;

     dp[0]=arr[0];//初始化
     int max=dp[0];
     *c1=0;
     *c2=0;

    int t1=0,t2=0;
     for(i=1;i<length;i++)
     {
         if(dp[i-1]>0)
         {
            dp[i]=dp[i-1]+arr[i];
            t2=i;// 更新尾部
         }
         else
         {
             dp[i]=arr[i];
             t2=i;
             t1=i;
        }
         if(dp[i]>max)
         {
             max=dp[i];
             *c1=t1;
             *c2=t2;
         }
     }
     return max;
 }
int* getMaxMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int arr[*matrixColSize];//辅助数组

    int mark[matrixSize][*matrixColSize];//辅助二维数组
    int i,j,k;

    for(i=0;i<matrixSize;i++)//初始化辅助数组
        for(j=0;j<*matrixColSize;j++)
        if(i==0)
        mark[i][j]=matrix[i][j];
        else
        mark[i][j]=mark[i-1][j]+matrix[i][j];

    int r1=0,c1=0,r2=0,c2=0;
    int max=-999999999;
    int h1,l1,h2,l2;
    for(i=0;i<matrixSize;i++)
        for(j=i;j<matrixSize;j++)
        {
            for(k=0;k<*matrixColSize;k++)
            {
                if(i==0)//初始化辅助数组
                arr[k]=mark[j][k];
                else
                arr[k]=mark[j][k]-mark[i-1][k];    
            } 
        if(CountMax(arr,k,&l1,&l2)>max)//更新最大值
        {
            max=CountMax(arr,k,&l1,&l2);
            c1=l1;c2=l2;
            r1=i;
            r2=j;
        }
        }
       // printf("the max is %d\n",max);
    int *result=(int *)malloc(sizeof(int)*4);
    *returnSize=4;
    result[0]=r1;
    result[1]=c1;
    result[2]=r2;
    result[3]=c2;
    return result;
}
```