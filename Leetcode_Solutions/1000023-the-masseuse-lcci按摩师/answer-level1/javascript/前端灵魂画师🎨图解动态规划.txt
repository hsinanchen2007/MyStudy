![image.png](https://pic.leetcode-cn.com/05b668899cccedc3d2b85a452a9b9bb492e25c44b92941c5ab6bc6918b316475-image.png)

![image.png](https://pic.leetcode-cn.com/a0ed1d053f6b1c40e37a7cea7b8a26b344854482b31028c2458e193c5c2f5d7c-image.png)



### 解题思路
基本的规律, 从前往后选择时, 当选择某个数字时, 必然会选择其后面第二个或者第三个数字, 从后往前选择同理

先画递归树

示例:  [ 2, 1, 4, 5, 3, 1, 1, 3 ]
其索引:  0  1  2  3  4  5  6  7

从前往后模拟计算过程, 选择的索引构成的树为
![image.png](https://pic.leetcode-cn.com/a94958a6a618f3bca54ea4d7cf56efba15f6fce991f46c93c809edb1604f5fca-image.png)

其中索引选择为 0, 2, 4, 7 的和最大, 即 2 + 4 + 3 + 3 = 12
### 代码

##### 先递归实现
```JavaScript
var massage = function(nums) {
  const len = nums.length
  if (len === 0) {
    return 0
  } else if (len === 1) {
    return nums[0]
  } else if (len === 2) {
    return Math.max(nums[0], nums[1])
  } else if (len === 3) {
    return Math.max(nums[1], nums[0] + nums[2])
  }
  let res = 0
  for (let index = 0; index < len; ++index) {
    // 包含这个数字时, 下一个数字可能是后面第二个数字或者后面第三个数字
    const curSelect = nums[index] + Math.max(massage(nums.slice(index + 2)), massage(nums.slice(index + 3)))
    // 更新最大数字
    res = Math.max(curSelect, res)
  }
  return res
};
```

##### 再记忆化搜索实现
```javascript
var massage = function(nums) {
  const len = nums.length
  if (len === 0) {
    return 0
  } else if (len === 1) {
    return nums[0]
  } else if (len === 2) {
    return Math.max(nums[0], nums[1])
  } else if (len === 3) {
    return Math.max(nums[1], nums[0] + nums[2])
  }
  const memory = {
    0: nums[0],
    1: Math.max(nums[0], nums[1]),
    2: Math.max(nums[1], nums[0] + nums[2])
  }
  // 获取到当前索引的最大结果
  function getCurMax (index) {
    if (index < 0) {
      return 0
    }
    if (memory[index] === undefined) {
      // 如果选择这个数字
      const selectCur = nums[index] + Math.max(getCurMax(index - 2), getCurMax(index - 3))
      // 如果不选择这个数字
      const notSelectCur = Math.max(getCurMax(index - 1), getCurMax(index - 2))
      memory[index] = Math.max(selectCur, notSelectCur)
      return memory[index]
    } else {
      return memory[index]
    }
  }
  let res = 0
  for (let index = 0; index < len; ++index) {
    res = Math.max(getCurMax(index), res)
  }
  return res
};
```