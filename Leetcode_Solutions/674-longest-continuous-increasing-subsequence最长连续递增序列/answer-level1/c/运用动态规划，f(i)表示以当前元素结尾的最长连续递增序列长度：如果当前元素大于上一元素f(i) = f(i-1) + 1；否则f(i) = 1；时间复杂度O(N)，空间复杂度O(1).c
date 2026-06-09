### 解题思路
此处撰写解题思路

### 代码

```c
int findLengthOfLCIS(int* nums, int numsSize){
    if(numsSize==0){
        return 0;
    }
    int max_length =1,current_length=1;
    for(int i = 1;i<numsSize;++i){
        if(nums[i]>nums[i-1]){  //如果上一个数f(i)=f(i-1)+1
            current_length += 1;
        }
        else{
            current_length = 1;
        }
        max_length = current_length>max_length?current_length:max_length;
    }
    return max_length;
}
```