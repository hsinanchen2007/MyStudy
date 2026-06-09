### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX(a,b)(a>b?a:b)

int maxSubArray(int* nums, int numsSize){
    if(nums == NULL || numsSize < 0){
        return INT_MIN;
    } 
    if(numsSize == 0){
        return 0;
    }
    int max = INT_MIN , sum = 0;
    for(int i = 0; i < numsSize ; i++){
        sum = MAX(sum+ nums[i] , nums[i]);
        max = MAX(max,sum);
    }
    return max;
}
```