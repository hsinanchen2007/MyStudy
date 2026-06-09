
**效率：**

平均执行用时 68ms，至少打败 80%，内存消耗 34.1MB 稳定，均打败 97%。
通过 Map 和对象的测试，Map 胜。并且改为尾递归后，内存消耗更是降低了 1MB+，用时也稳定提升了。

**代码：**

``` javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
  let targetMap = new Map()
  for (let i = nums.length - 1; i >= 0; i--) {
    const key = target - nums[i]
    if (targetMap.has(key)) return [targetMap.get(key), i]
    targetMap.set(nums[i], i)
  }
};
```

**题外**：
这道题目和121股票买卖最佳时间的思路，两者有共同点：全局得出数字的关系，根据规则局部一步一步推进，性能就提上去了。

**参考解法**：

① [【JavaScript+ES6】两数之和](https://leetcode-cn.com/problems/two-sum/solution/javascriptes6jie-jue-fang-shi-by-a-xing-29/)
② [javascript两数之和（从龟速到最速）](https://leetcode-cn.com/problems/two-sum/solution/javascriptliang-shu-zhi-he-cong-gui-su-dao-zui-su-/)

我最开始的解法性能一般，查看题解优化了解法。代码结合了参考解法的两篇文章，代码量降低、性能进步很大。