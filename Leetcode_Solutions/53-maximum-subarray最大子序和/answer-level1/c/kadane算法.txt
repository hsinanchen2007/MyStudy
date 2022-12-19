### 解题思路
此处撰写解题思路

### 代码

```c
//https://blog.csdn.net/lengxiao1993/article/details/52303492

#define max(x,y) (x > y ? x : y)
int maxSubArray(int* nums, int numsSize){
    //max_ending_here 以i结尾的最大连续子数组和
    //max_so_far 最大子数组和中的最大值
    int max_ending_here = nums[0];
    int max_so_far = nums[0];
    for (int i = 1; i < numsSize; i++) {
        max_ending_here = max(nums[i], max_ending_here + nums[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}
```