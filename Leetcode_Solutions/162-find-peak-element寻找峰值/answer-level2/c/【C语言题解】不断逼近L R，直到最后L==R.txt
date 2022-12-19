### 解题思路
![image.png](https://pic.leetcode-cn.com/2f19f507955ee65db8558e39403a1075da1032970734d7bd52f84b5cbbfd6023-image.png)

不断逼近L R，直到最后L==R
不清楚最后return L/R，取mid就好了
### 代码

```c
int findPeakElement(int* nums, int numsSize){
    if(nums==NULL || numsSize==1) return 0;

    // 要求使用logN的时间复杂度，因此肯定是使用二分法
    int left = 0, right = numsSize-1, mid;

    while(left<right) {
        mid = (left + right) /2;

        if(nums[mid]>nums[mid+1]) {  // 找左边
            right = mid;
        }else if(nums[mid]<nums[mid+1]){  // 找右边
            left = mid+1;       
        }
    // printf("%d-%d\n",left,right);
    }
    mid = (left + right) /2;
    return mid;
}
```