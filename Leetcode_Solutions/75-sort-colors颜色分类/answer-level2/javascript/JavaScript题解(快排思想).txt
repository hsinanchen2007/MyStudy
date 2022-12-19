### 解题思路
维护两个区域(0区和2区)，遍历数组把遍历元素划分到各个区中。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function (nums) {
    if (!Array.isArray(nums)) console.log('Invaild Input');
    if (!nums.length) return []
    let [cur, left, right] = [0, 0, nums.length - 1];
    const swap = (a, b) => {
        let temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    };
    while (cur <= right) {
        if (nums[cur] === 0) {
            swap(left, cur);
            left++;
            cur++
        } else if (nums[cur] === 2) {
            swap(cur, right);
            right--;
        } else {
            cur++
        }
    }
    return nums
};
```
![搜索框传播样式-标准色版.png](https://pic.leetcode-cn.com/5b693dce2ea930fe7d095fbb126cc9e8b0d109de3e59c4f09c898d62a09d7a9b-%E6%90%9C%E7%B4%A2%E6%A1%86%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)
