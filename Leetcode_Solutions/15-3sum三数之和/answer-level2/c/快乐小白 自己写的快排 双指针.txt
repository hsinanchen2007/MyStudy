### 解题思路


c语言做的 报个坑 第311个案例溢出 我找了 好久 *returnColumnSizes = (int*)malloc(sizeof(int) * (numsSize)*(numsSize)); 题目自身给的不够大 在大一点    醉了

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void qsort1(int *nums,int left,int right)
{
    if(left>=right)
    return;
    int i=left;
    int j=right;
    int key=nums[i];
    while(i<j)
    {
        while(i<j&&nums[j]>=key)
        {
            j--;
        }
        nums[i]=nums[j];
        while(i<j&&nums[i]<=key)
        {
            i++;
        }
        nums[j]=nums[i];
    }
    nums[i]=key;
    qsort1(nums,left,i-1);
    qsort1(nums,i+1,right);
} 

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize=0;
    if( numsSize < 3 )
    {
        return NULL;
    }
    qsort1(nums,0,numsSize-1);
    int **a=(int **)malloc(sizeof(int*)* (numsSize)*(numsSize));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (numsSize)*(numsSize));
    for(int i=0;i<numsSize-2;i++)
    {
        if(nums[i]>0)
        break;
        if(i!=0)
        {
            if(nums[i]==nums[i-1])
            continue;
        }
        int j=i+1;
        int z=numsSize-1;
        while(j<z)
        {
            if(nums[i]+nums[j]+nums[z]>0)
            {
                z--;
            }else if(nums[i]+nums[j]+nums[z]<0)
            {
                j++;
            }else
            {
                a[*returnSize]=(int *)malloc(sizeof(int )*3);
                (*returnColumnSizes)[*returnSize] = 3;
                a[*returnSize][0]=nums[i];
                a[*returnSize][1]=nums[j];
                a[(*returnSize)++][2]=nums[z];

                while(j<z&&nums[j]==nums[j+1])
                {
                    j++;
                }
                while(j<z&&nums[z]==nums[z-1])
                {
                    z--;
                }
                j++;
                z--;
            }
        }      
    }
    return a;
}
```