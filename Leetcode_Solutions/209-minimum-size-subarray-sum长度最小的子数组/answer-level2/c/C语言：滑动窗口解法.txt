题目明明说找出子串，写的半天，发现返回值类型是int，返回的应该是子串长度。这题目描述不到位。
滑动窗口一般用于解决找出查找满足一定条件的**连续区间**的性质（长度等）的问题。
一般右指针自然向右滑动，找到滑动条件非常关键，找到即可以得到题解。

```
int min(int a, int b){
    return (a<b)?a:b;
}

int minSubArrayLen(int s, int* nums, int numsSize){
    int left = 0;
    int right = 0;
    int subSum = 0;
    int subLen = 0;

    while(right < numsSize){
        subSum += nums[right];
        if (subSum >= s){
            while((subSum - nums[left]) >= s){
                subSum -= nums[left];
                left++;
            }
            if (subLen == 0){
                subLen = right - left + 1;
            } else {
                subLen = min(subLen, right - left + 1);
            }
            
            if (subLen == 1){
                return subLen;
            }
        }
        right++;
    }
    return subLen;
1. }
```
