### 解题思路
课本代码

### 代码

```c
int search(int* nums, int numsSize, int target){
    int low=0,high=numsSize-1,flag=0,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(nums[mid]>target){
            high=mid-1;
        }else if(nums[mid]<target){
            low=mid+1;
        }else{
            flag=1;
            break;
        }
    }
    return flag==1?mid:-1;
}
```