### 解题思路
明确解题思路, 再考虑最佳方案
思路: 两数之和, 意味着数组里的每个元素彼此之间都要试着相加一下, 看是否等于目标值
方案: 最简单直接的方式就是两个 for 循环, 但效率不高, 访问每个元素都需要遍历. 因此我们可以在这上面做一下优化.
用一个 for 循环加一个 Map 用来存储访问元素. 这样, 通过空间换时间, 执行效率会高一些

### 代码

```javascript
  /**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    // 声明 Map 来存储访问过的元素
    const map = new Map()

    // 遍历数组, 访问过的元素存储在 Map, 用于对比
    for (let i = 0; i < nums.length; i++) {
      const differ = target - nums[i]
      if (map.has(differ)) {
        return [map.get(differ), i]
      }
      map.set(nums[i], i)
    }
};
```