### 解题思路
此处撰写解题思路

### 代码

```c
int findMaxConsecutiveOnes(int* nums, int numsSize){
        long n=0,max=0;
        for(int i=0;i<numsSize;i++){
            if(nums[i]==1){
                max++;
            }
            else {
        if(n<max){
           n= max;
        }
        max=0;
            }
        }
        if(n<max){
           n= max;
        }
        return n;
}
```