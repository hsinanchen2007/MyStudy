/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/27
 * 
 * 解题思路: 记忆法 滑动窗口 当移动一位的时候 只需要减去前一个i - 1 加上新的一个i + k - 1
 * 
 */
```
 public double findMaxAverage(int[] nums, int k) {
    double sum = 0;
    for(int i = 0;i < k; i++){
        sum += nums[i];
    }

    double t = sum;
    for(int i = 1;i < nums.length - k + 1;i++){

        t = t - nums[i - 1] + nums[ i + k - 1]; // 前去前一个i-1元素 加上新增的 i+k-1 个元素
        sum = Math.max(sum,t);

    }
    return sum/k;
}
```