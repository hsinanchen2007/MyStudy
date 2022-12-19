### 解题思路
此处撰写解题思路

### 代码

```c

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int campare(const void *a,const void *b){
     return *(int *)a-*(int *)b;
 }
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    
    int **result=NULL;
    
    int low;
    int high;
    int sum;
    int key=0;
    *returnSize=0;
    qsort(nums,numsSize,sizeof(int),campare); 
    result=(int **)malloc(sizeof(int *)*numsSize*numsSize);
    if(numsSize<4)return result;
    for(int i=0;i<numsSize-3;i++){
        while(nums[i]==nums[i-1]&&i>0&&i<numsSize-3)i=i+1;
        for(int j=i+1;j<numsSize-2;j++){
            while(nums[j]==nums[j-1]&&(j>i+1)&&j<numsSize-2)j=j+1;
            
            low=j+1;
            high=numsSize-1;
            sum=nums[i]+nums[j];
            sum=target-sum;
            while(low<high&&low<numsSize&&high<numsSize){
                if(nums[low]+nums[high]>sum){
                    high--;
                }
                else if(nums[low]+nums[high]<sum){
                    low++;
                }
                else{
                    (*returnColumnSizes)[key] = 4;
                    result[key]=(int *)malloc(sizeof(int)*4);
                    result[key][0]=nums[i];
                    result[key][1]=nums[j];
                    result[key][2]=nums[low];
                    result[key][3]=nums[high];
                    key++;
                    while(nums[low]==nums[low+1]&&low+1<high){
                        low++;
                        
                    }
                    while(nums[high]==nums[high-1]&&high-1>low){
                        high--;
                    }
                        low++;
                        high--;

                }
            }
        }
        
    }
    
    (*returnSize)=key;

    return result;
}
```