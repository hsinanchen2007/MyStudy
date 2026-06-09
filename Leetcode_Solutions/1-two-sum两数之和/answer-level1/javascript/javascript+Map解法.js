### 解题思路
其实「两个数字的和」可以变成「在这个数组中目标与查找当前元素的差值」

所以建立一个哈希集，key为「目标值和当前元素的差值」，value是「当前元素下标」。

然后跟后续的元素对比，当后续元素跟「某个差值」对上了，则可以返回结果。

如果哈希集里面没有这个「差值」，则加入。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
  let map = new Map();
  for(let i = 0; i < nums.length; i++) {
    if (!map.has(nums[i])) {
      map.set(target - nums[i], i);

    } else {
      let index = map.get(nums[i]);
      return [index, i]
    }
  }
};
```