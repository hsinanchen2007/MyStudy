### 解题思路
纯ES6写法，利用新的数据结构Map

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
let twoSum = (nums, target) => {
    let targetMap = new Map()
    for (let i = 0; i < nums.length; i++) {
      const key = target - nums[i]
      if (targetMap.has(key)) {
        return [targetMap.get(key), i]
      }
      targetMap.set(nums[i], i)
    }
  }
twoSum([5, 2, 11, 15, 7, 6], 9)

// 普通写法
var twoSum = function(nums, target) {
    let targetMap = {}
    for (let i = 0; i < nums.length; i++) {
      // 该元素对应的另一个元素,作为键名
      let key = target - nums[i]
      // 如果存在该值，则之前存在对应的另一个值
      if (targetMap[key] || targetMap[key] === 0) {
        return [targetMap[key], i]
      }
      // 建立映射关系
      targetMap[nums[i]] = i
    }
  }
twoSum([5, 2, 11, 15, 7, 6], 9)
```