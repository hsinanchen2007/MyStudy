 方法挺好想的，找一下规律就好了，首先对数组进行原地转置，之后再对二维数组中的每一个数组，也就是数组的每一行，进行数组逆置，这里用了双指针进行逆置，即可。
```
void rotate(int** matrix, int matrixSize, int* matrixColSize){
  
     int temp=0;
    for(int i=0;i<matrixSize;i++)
    {
        for(int j=i;j<*matrixColSize;j++)
        {
            temp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
    }
    for(int i=0;i<matrixSize;i++)
    {
        jiaohuan(matrix[i],*matrixColSize,0,*matrixColSize-1);
    }
    
    
}
void jiaohuan(int* arr,int length,int i,int j)
{
    int temp=0;
    while(i<j)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
    
}
```
