### 解题思路
对区间左端点进行快排，然后把每个区间和它后边第一个区间进行比较，三种情况：①没重叠②有重叠③不只是重叠，后者完全是前者的子集。
注意：更新二维数组result【】【】的时候，直接更新一下一维数组的头地址就行了。
### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void QuickSort(int low,int high,int** intervals){
    if(low<high){
        int i = low,j = high;
        int pivot = intervals[low][0];
        int* pointpivot = intervals[low];
        while(low<high){
            while(low<high && intervals[high][0]>=pivot) high--;
            intervals[low] = intervals[high];
            while(low<high && intervals[low][0]<=pivot) low++;
            intervals[high] = intervals[low];
        }
        intervals[low] = pointpivot;
        QuickSort(i,low-1,intervals);
        QuickSort(low+1,j,intervals);
    }    
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    if(intervalsSize < 2){
        *returnSize = intervalsSize;
        if(intervalsSize == 1){
            (*returnColumnSizes) = (int*)malloc(sizeof(int)*intervalsSize);
            (*returnColumnSizes)[0] = 2;
        }    
        return intervals;
    }
    *returnSize = 0;
    int** result = (int**)malloc(sizeof(int*)*intervalsSize);
    (*returnColumnSizes) = (int*)malloc(sizeof(int)*intervalsSize);
    QuickSort(0,intervalsSize-1,intervals);
    for(int i=0;i<intervalsSize-1;i++){
        if(intervals[i][1] >= intervals[i+1][0]){     //有重叠部分，更新后者的左端点
            intervals[i+1][0] = intervals[i][0];       
            if(intervals[i+1][1] < intervals[i][1]){   //不光是有重叠部分，后边的区间是前边区间的子集
                intervals[i+1][1] = intervals[i][1];    //更新后者的右端点
            }  
        }else{                                        //没有重叠，更新result
            result[*returnSize] = intervals[i];
            (*returnColumnSizes)[(*returnSize)++] = 2;
        }
    }
    result[*returnSize] = intervals[intervalsSize-1];   //最后的区间后边没区间可以比较，单独拿出来处理
    (*returnColumnSizes)[(*returnSize)++] = 2;
    return result;
}
```