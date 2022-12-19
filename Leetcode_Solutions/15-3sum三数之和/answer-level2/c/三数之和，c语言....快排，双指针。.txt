### 解题思路
// （*returnColumnSizes）[]  用来存储每行的列数...不知道有什么屌用...
//思想就是快排变成有序数列，然后两层循环，第二层循环使用双指针low，high。每次提交执行时间都不一样，很费解

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int Partion(int* A,int low,int high){
    int pivot = A[low];
    while(low<high){
        while(A[high]>=pivot && high>low){
            high--;
        }
        A[low] = A[high];
        while(A[low]<=pivot && low<high){
            low++;
        }
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(int *A,int low,int high){
    if(low<high){
        int mid = Partion(A,low,high);
        QuickSort(A,low,mid-1);
        QuickSort(A,mid+1,high);
    }
}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if(numsSize<3){
        return NULL;
    }
    QuickSort(nums,0,numsSize-1);
    int **result = (int**)malloc(sizeof(int*)*(numsSize*numsSize));
    *returnColumnSizes = (int*)malloc(sizeof(int)*(numsSize*numsSize));
    int i=0,low,high;
    while(nums[i]<=0 && i<numsSize-2){
        low=i+1,high=numsSize-1;
        while(low<high){
            if(nums[i]+nums[low]+nums[high]<0){
                low++;
            }else if(nums[i]+nums[low]+nums[high]>0){
                high--;
            }else{
                result[*returnSize] = (int*)malloc(sizeof(int)*3);
                (*returnColumnSizes)[*returnSize] = 3;
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[low];
                result[(*returnSize)++][2] = nums[high];
                while(nums[low]==nums[++low] && low<high);      //排除重复答案
                while(nums[high]==nums[--high] && high>low);    //排除重复答案
            }
        }
        while(nums[i]==nums[++i] && i<numsSize-2);                 //排除重复答案
    }
    return result;
}
```