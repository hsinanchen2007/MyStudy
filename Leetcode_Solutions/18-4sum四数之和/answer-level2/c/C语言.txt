
```
int partition(int *nums,int low,int high){
    int pivot=nums[low];
    while (low<high){
        while (nums[high]>=pivot&&low<high)
            high--;
        nums[low]=nums[high];
        while (nums[low]<=pivot&&low<high)
            low++;
        nums[high]=nums[low];
    }
    nums[low]=pivot;
    return low;
}

void quick_sort(int *nums,int low,int high){
    int pivot;
    if (low<high){
        pivot=partition(nums,low,high);
        quick_sort(nums,low,pivot-1);
        quick_sort(nums,pivot+1,high);
    }
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    quick_sort(nums,0,numsSize-1);
    int **ans=(int **)malloc(sizeof(int *)*numsSize*6);
    int key1,key2,i,j;

    *returnColumnSizes =(int *)malloc(sizeof(int) *numsSize*6);
    *returnSize=0;

    for(key1=0;key1<numsSize;key1++){ 
        if (key1>0&&nums[key1]==nums[key1-1])//key1去重
            continue;
        for(key2=key1+1;key2<numsSize;key2++){
            if (key2>key1+1&&nums[key2]==nums[key2-1])//key2去重
                continue;
            i=key2+1;
            j=numsSize-1;
            while(i<j){
                if(nums[key1]+nums[key2] + nums[i] + nums[j]==target){
                    ans[*returnSize]=(int *)malloc(sizeof(int)*4);
                    ans[*returnSize][0]=nums[key1];
                    ans[*returnSize][1]=nums[key2];
                    ans[*returnSize][2]=nums[i];
                    ans[*returnSize][3]=nums[j];
                    returnColumnSizes[0][*returnSize]=4;
                    (*returnSize)++;//*returnSize别忘了加括号
                    while(i<j&&nums[i]==nums[i+1]) 
                        i++;//去重
                    while(i<j&&nums[j]==nums[j-1]) 
                        j--;//去重
                    i++;
                    j--;
                }
                else if(nums[key1]+nums[key2] + nums[i] + nums[j]>target) 
                    j--;
                else 
                    i++;
            }
        }
    }
    return ans;
}
```
