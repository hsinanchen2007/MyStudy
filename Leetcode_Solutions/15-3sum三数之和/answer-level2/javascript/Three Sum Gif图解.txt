## 解题方法
该解法只是参照了另一个题解，[Three Sum题解](https://leetcode-cn.com/problems/3sum/solution/three-sum-ti-jie-by-wonderful611/)，本人只是将其可视化，方便大家理解
### 原理
- 先将数组进行排序
- 从左侧开始，选定一个值为 `定值` ，右侧进行求解，获取与其相加为 $0$ 的两个值
 - 类似于快排，定义首和尾
 - 首尾与 `定值` 相加
    1. 等于 $0$，记录这三个值
    2. 小于 $0$，首部右移
    3. 大于 $0$，尾部左移
- 定值右移，重复该步骤
### 图解

![Video_2019-06-19_192352.gif](https://pic.leetcode-cn.com/2124b524439bcf0eb159ba43be4420c76f60ff2b3b51f87de269c001a323ea1a-Video_2019-06-19_192352.gif)
### 代码
```js [-JavaScript]
var threeSum = function(nums) {
  // 最左侧值为定值，右侧所有值进行两边推进计算
  let res = [];
  nums.sort((a, b) => a - b);
  let size = nums.length;
  if (nums[0] <= 0 && nums[size - 1] >= 0) {
    // 保证有正数负数
    let i = 0;
    while (i < size - 2) {
      if (nums[i] > 0) break; // 最左侧大于0，无解
      let first = i + 1;
      let last = size - 1;
      while (first < last) {
        if (nums[i] * nums[last] > 0) break; // 三数同符号，无解
        let sum = nums[i] + nums[first] + nums[last];
        if (sum === 0) {
          res.push([nums[i], nums[first], nums[last]]);
        }
        if (sum <= 0) {
          // 负数过小，first右移
          while (nums[first] === nums[++first]) {} // 重复值跳过
        } else {
          while (nums[last] === nums[--last]) {} // 重复值跳过
        }
      }
      while (nums[i] === nums[++i]) {}
    }
  }

  return res;
};
```