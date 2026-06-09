### 解题思路
此处撰写解题思路

### 代码

```c
void reverse(int* nums,int start,int end){
    while(start<end){
        int temp = nums[start];
        nums[start]=nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}
void rotate(int* nums, int numsSize, int k){
    k%=numsSize;
    reverse(nums,0,numsSize-1);
    reverse(nums,0,k-1);
    reverse(nums,k,numsSize-1);
}
```