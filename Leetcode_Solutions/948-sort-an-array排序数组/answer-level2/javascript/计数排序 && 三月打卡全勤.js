// ![counterSort.png](https://pic.leetcode-cn.com/61bff0fa87eba6f790981e81847027be0ec133c3f78f399083d45f3133cc4254-counterSort.png)
// ![March day.png](https://pic.leetcode-cn.com/409bfac234a1e10a929a2d1559e5e9c102c051149bc49a3f626e711cea1bf214-March%20day.png)
// ![March.png](https://pic.leetcode-cn.com/50a6908c5bebbec4126592f38ef8e38d9e70b7ca91d438d8c6fdd6084d3ad624-March.png)



// ### 解题思路
// 因为数据范围有限， 可利用计数排序

// ### 代码
// 先体力活儿💪搬运一个api水一波
// ```javascript
var sortArray = function(nums) {
    return nums.sort((a, b) => a - b)
};
// ```


// 计数排序
// ```javascript
var sortArray = function(nums) {
  let min = 50000
  let max = -50000
  nums.forEach(item => {
    if (item > max) {
      max = item
    }
    if (item < min) {
      min = item
    }
  })
  const counterArr = new Array(max - min + 1)
  for (let i = 0; i < nums.length; ++i) {
    if (counterArr[nums[i] - min] === undefined) {
      counterArr[nums[i] - min] = 1
    } else {
      ++counterArr[nums[i] - min]
    }
  }
  const res = []
  counterArr.forEach((item, index) => {
    while (item > 0) {
      res.push(min + index)
      --item
    }
  })
  return res
};
// ```