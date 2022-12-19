该题是基础全排列的变种，主要在于去重。

针对同一层次的计算，对连续的相同的元素只选取一个进行后续的替换，即可等价于基础全排列。例如，当前层次是[1,2, 1, 2], 我们可以只选取第一次出现的元素作为替换： 对于第一个元素1， 第一次出现，则其结果为1与[2, 1, 2]的所有全排列的连接，标记1已使用；对于第二个元素2，2未使用，则其结果为2与[1, 1, 2]的全排列的连接，并标记2已使用; 对于第3个元素1，其已使用，跳过；对于最后一个元素2，由于2已使用，跳过。


![permute(8).png](https://pic.leetcode-cn.com/895eac424643942318f8f9eb2bd8d33c86f28d795d4d586b25b59921dc5cddf1-permute\(8\).png)




```
var swap = function(nums, i, j) {
    if (i === j)
        return;
    const t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
};

var cal = function (nums, first, result) {
    if (nums.length === first) {
        result.push([...nums]);
        return;
    }

    const map = new Map();
    for (let i = first; i < nums.length; i++) {
        if (!map.get(nums[i])) {
            map.set(nums[i], true);
            swap(nums, first, i);
            cal(nums, first + 1, result);
            swap(nums, first, i);
        }
    }
};

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function(nums) {
    if (nums == null)
        return;
    
    nums.sort((a, b) => a - b);
    const res = [];
    cal(nums, 0, res);
    return res; 
};
```

