### 解题思路
执行用时 :8 ms, 在所有 C 提交中击败了95.44%的用户
内存消耗 :6.1 MB, 在所有 C 提交中击败了100.00%的用户

### 代码

```c
int findLengthOfLCIS(int* nums, int numsSize){
    if(numsSize<2)
        return numsSize;
    int cnt=1,t=nums[0],max=1;
    for(int i=1;i<numsSize;i++){
        if(nums[i]>t){
            cnt++;
            t=nums[i];
        }
        else{
            max=max>cnt?max:cnt;
            cnt=1;
            t=nums[i];
        }
    }
    return max>cnt?max:cnt;
}
```