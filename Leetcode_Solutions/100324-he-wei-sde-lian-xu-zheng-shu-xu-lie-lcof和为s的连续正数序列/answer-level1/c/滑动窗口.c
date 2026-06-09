### 解题思路
参看两位大佬写的

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int **reslut=(int**)malloc(sizeof(int*)*target);
    int *res=(int*)malloc(sizeof(int)*target);  //此处应该可优化
    int i,j,sum,index;
    i=j=1;index=sum=0;  //i,j为窗口左右边界,左闭右开
    while(i<=target/2){
        if(sum<target){ //小于目标值,右边界右移
            sum+=j;
            j++;
        }
        else if(sum>target){//大于目标值,左边界右移
            sum-=i;
            i++;
        }
        else{
            res[index]=j-i;//每个数组中元素的个数     
            reslut[index]=(int*)malloc(sizeof(int)*(j-i));//分配列
            for(int x=i,y=0;x<j;x++,y++)reslut[index][y]=x;
            index++;
            sum-=i;
            i++;           
        }
    }
    *returnSize=index;
    *returnColumnSizes=res;
    return reslut;
}
```