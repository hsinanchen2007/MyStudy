### 解题思路
此处撰写解题思路

### 代码

```c
int firstMissingPositive(int* nums, int numsSize){
    const int n = numsSize;
    int p[n+2];
    memset(p,0,sizeof(int)*(numsSize+2));
    for(int i = 0;i < numsSize;i++){
        if(nums[i]>0&&nums[i]<=numsSize){
            *(p+nums[i]) = nums[i];

        }
    }
    for(int j = 1;j <= numsSize+1;j++){ //numsSize+1个数字里面至少有一个0
        if(*(p+j) == 0)
            return j;
    }
    return 0;
}
```