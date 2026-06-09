### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 //在函数内malloc 要考虑到在函数外的释放
//returnColumnSizes is the address of a pointer(int *)
//the pointer's object can be changed by using :(*returnColumnSizes)=...
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    * returnSize=numRows;
    int **TwoDmsArray=(int **)malloc(sizeof(int*)*numRows);
    //TwoDmsArray[i] is a pointer which starts the rows;
    //returnColumnSizes is a pointer which tells the element number of each line
        //and its object can be changed.so it can be sent as a NULL,and then worked 
        // when the array is malloced in a function and freed later in anthor funtion.
        //it is passed to free the memory.
    (*returnColumnSizes)=(int *)malloc(sizeof(int)*numRows);

    //calculate the triangle
     for(int i=0;i<numRows;i++)
    {
        TwoDmsArray[i]=(int *)malloc(sizeof(int)*(i+1));
        TwoDmsArray[i][0]=1;
        TwoDmsArray[i][i]=1;
        for(int j=1;j<i;j++)
        {
            TwoDmsArray[i][j]=TwoDmsArray[i-1][j-1]
            +TwoDmsArray[i-1][j];
            
        }
        (*returnColumnSizes)[i]=i+1;
    
    }
    return TwoDmsArray;


}
```