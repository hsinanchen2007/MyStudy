### 解题思路
拿到题目后，最开始的想法是使用for循环遍历，但是for循环遍历的话难免会出现多次取同一个值的问题，所以转投indexOf,提交方案之后发现耗时228ms，击败1%的敌人，不过好在内存超过90%。那么有没有物美价廉的方法呢？手动尝试了优化代码，包括后序遍历，pop元素等方法，无奈还是效果不佳，最后只得看官方答案，发现使用es6的map方法是最快的，亲测可用，那么官方答案有没有优化空间呢？所以我尝试了后序遍历+map.get方案，仁者见仁，相信还有其他的优化方案，继续思考吧

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let map = new Map();
  for (let i = nums.length - 1; i > -1 ; i--) {
    let a = map.get(target-nums[i]);
    if (undefined !== a) {
      return [i,a]
    }
    map.set(nums[i], i);
  }
};
```