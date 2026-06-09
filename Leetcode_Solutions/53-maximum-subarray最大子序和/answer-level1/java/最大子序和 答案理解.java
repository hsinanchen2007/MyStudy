看了答案，觉得有点懵逼，选择了相对好理解的一种解题方式，补充一下个人的理解
```
    int n = nums.length;
        // 取数组第一位作为当前最大值，总最大值
        int currSum = nums[0], maxSum = nums[0];

        for(int i = 1; i < n; ++i) {
            // 遍历比较 数组每一位 与 这一位与前一次遍历获得的当前最大值的和  大的作为当前最大值
            currSum = Math.max(nums[i], currSum + nums[i]);
            // 比较 此次轮询当前最大值 与 前一次总最大值 大的作为总最大值
            maxSum = Math.max(maxSum, currSum);
        }
        // 即记录两个最大值（当前，总），可以解决比如数组前几个是整数，中间出现了负数，再出现正数，有可能在几次遍历         // 之后总和会大于最初几个正数和的情况
        return maxSum;
```
希望可以帮助理解