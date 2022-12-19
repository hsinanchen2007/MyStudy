**方法一**
**动态规划+线性查找**
```
int Max(int a, int b){
    return a<b?b:a;
}
int lengthOfLIS(int* nums, int numsSize){
    if(numsSize < 2) return numsSize;
    int dp[numsSize];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    int maxsubsequence = 0;
    for(int i=1; i<numsSize; i++){
        int tmp = 1;
        for(int j=0; j<i; j++){
            if(nums[i]>nums[j])
                tmp = Max(tmp, dp[j]+1);
        }
        dp[i] = tmp;
        maxsubsequence = Max(dp[i], maxsubsequence);
    }
    return maxsubsequence;
}
```
**复杂度分析**
- 时间复杂度：O(n^2)，程序包含双层循环
- 空间复杂度：O(n)，用了大小为 n 的矩阵 dp


**方法二**
**动态规划+二分查找**
```
int lengthOfLIS(int* nums, int numsSize){
    if(numsSize < 2) return numsSize;
    int tail[numsSize];
    memset(tail, 0, sizeof(tail));
    int len = 0;
    for(int i=0; i<numsSize; i++){
        int left = 0, right = len;
        // 采用二分查找
        while(left < right){
            int mid = (left+right)/2;
            if(nums[i] <= tail[mid]) right = mid;
            else left = mid+1;
        }
        tail[left] = nums[i];
        if(left == len) len++;
    }
    return len;
}
```
**复杂度分析**
- 时间复杂度：O(nlogn)外层循环遍历数组，内层循环二分查找
- 空间复杂度：O(n)，用了大小为 n 的矩阵tail

![image.png](https://pic.leetcode-cn.com/810ac9d75ecc7a23465d4c6307d1dd96c59bc90f9e265e8006d4c6d936cec829-image.png)
