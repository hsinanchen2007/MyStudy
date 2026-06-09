正常求子数组最大和:
参考题目：[53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/submissions/)
代码如下：
```java
class Solution {
    public int maxSubArray(int[] nums) {
        int ans = Integer.MIN_VALUE, sum = 0;
        for (int num : nums) {
            sum = Math.max(num, sum + num);
            //sum = sum > 0 ? sum + num : num;
            ans = Math.max(ans, sum);
        }
        return ans;
    }
}
```

而删除1次得到子数组最大和，就基于上述代码进行修改。
有2种方案：
1. 在sum < 0时，sum重置为0，然后继续累加。其中记录最小值min。当min < 0时，就删除min的值，删去后的子数组和为sum - min；若min > 0，则保留，即子数组和为sum。
2. 在sum - min < 0时，sum重置为0，然后继续累加。其中也记录最小值min。当min < 0时，就删除min的值，删去后的子数组和为sum - min；若min > 0，则保留，即子数组和为sum。

在2种方案中取 较优者即可。

# 代码：
```java
class Solution {
    public int maximumSum(int[] arr) {
        int len = arr.length;
        //数组长度为1，直接返回数组元素
        if (len < 2)
            return arr[0];
        //寻找数组中第1个非负数的下标
        int idx = 0, res = Integer.MIN_VALUE;
        while (idx < len && (res = Math.max(res, arr[idx])) < 0)
            ++idx;
        //说明整个数组都是负数，返回值最大的负数
        if (idx == len)
            return res;
        //pre_sum1在值为负时，即重置为0，重新累加。min1记录所遍历过的元素中值最小的元素。
        //pre_sum2在值 - min2值为负时，即重置为0，重新累加。min2记录所遍历过的元素中值最小的元素。
        int pre_sum1 = 0, min1 = Integer.MAX_VALUE;
        int pre_sum2 = 0, min2 = Integer.MAX_VALUE;
        res = Integer.MIN_VALUE;

        for (; idx < len; ++idx) {
            pre_sum1 += arr[idx];
            min1 = Math.min(min1, arr[idx]);

            res = min1 < 0 ? Math.max(res, pre_sum1 - min1) : Math.max(res, pre_sum1);

            if (pre_sum1 < 0) {
                pre_sum1 = 0;
                min1 = Integer.MAX_VALUE;
            }

            pre_sum2 += arr[idx];
            min2 = Math.min(min2, arr[idx]);

            res = min2 < 0 ? Math.max(res, pre_sum2 - min2) : Math.max(res, pre_sum2);

            if (pre_sum2 - min2 < 0) {
                pre_sum2 = 0;
                min2 = Integer.MAX_VALUE;
            }
        }

        return res;
    }
}
```
