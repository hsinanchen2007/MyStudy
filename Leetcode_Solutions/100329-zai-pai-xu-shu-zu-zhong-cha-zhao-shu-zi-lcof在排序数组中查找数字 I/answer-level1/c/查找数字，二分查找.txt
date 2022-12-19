### 解题思路
相当于寻找target在数组中的左右边界

### 代码

```c
int search(int* nums, int numsSize, int target){
    int head,tail,mid;
    head=0;tail=numsSize-1;
    while(head<=tail){
        mid=head+(tail-head)/2;
        if(nums[mid]<target){
            head=mid+1;
        }
        else if(nums[mid]>target){
            tail=mid-1;
        }
        else {
            tail=mid-1;     //向左，寻找左边界
        }
    }
    //if(head>=numsSize||nums[head]!=target) return 0;
    int left=head;
    head=0;tail=numsSize-1;
    while(head<=tail){
        mid=head+(tail-head)/2;
        if(nums[mid]<target){
            head=mid+1;
        }
        else if(nums[mid]>target){
            tail=mid-1;
        }
        else {
            head=mid+1;     //向右，寻找右边界
        }
    }
    int right=tail;
    return tail-left+1;
}
```