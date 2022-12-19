### 解题思路
先设置最大值max，由于不知道最大值的正负及大小情况，需将其设为最小值，由于Number.MIN_VALUE的值为正数，所以采用将-Number.MAX_VALUE赋给max的方法；
再求和，判断和是否小于零，因为只要前面的和小于0，那么后面的数加上前面的和就一定比自身小，所以又重新求和，并和之前的最大子序和比较，取最大值。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    var max = -Number.MAX_VALUE;
    var sum = 0;
    for(let num of nums)
    {
        if(sum<0)
        {
            sum = 0;
        }
        sum += num;
        max = Math.max(max, sum);
    }
    return max;
};
```