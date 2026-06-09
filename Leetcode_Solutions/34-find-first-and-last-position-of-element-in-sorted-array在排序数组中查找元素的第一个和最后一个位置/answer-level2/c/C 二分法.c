```
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int i=0,j=numsSize-1,mid;
    int *a = malloc(sizeof(int)*2);
    a[0]=a[1]=-1;
    if(numsSize==0)
        return a;
    while(i<j-1){
        mid=(i+j)/2;
        if(nums[mid]<target){
            i=mid+1;
        }else{
            j=mid;
        }
    }
    if(nums[i]==target){
        a[0]=i;
    }else if(nums[j]==target){
        a[0]=j;
    }
    i=0,j=numsSize-1;
    while(i<j-1){
        mid=(i+j)/2;
        if(nums[mid]<=target){
            i=mid;
        }else{
            j=mid-1;
        }
    }
    if(nums[j]==target){
        a[1]=j;
    }else if(nums[i]==target){
        a[1]=i;
    }
    *returnSize=2;
    return a;
}
```
