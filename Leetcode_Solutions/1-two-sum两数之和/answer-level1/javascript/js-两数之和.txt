### 解题思路

异常情况不考虑，默认数组长度是大于1的，且不存在重复元素；
两次遍历的想法就不考虑了。

1、创建一个map
2、从map中去寻找差值是不是存在


### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const map = new Map()
    for (let i = 0; i < nums.length; i++) {
        const delta = target - nums[i]
        if (map.has(delta)) {
            return [map.get(delta), i]
        }
        map.set(nums[i], i)
    }
};
```