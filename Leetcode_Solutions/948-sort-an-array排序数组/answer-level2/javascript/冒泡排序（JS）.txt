### 解题思路
这道题考察的各种排序算法的实现，先来一个最简单的冒泡排序

- 步骤1:比较相邻的元素。如果第一个比第二个大，就交换它们两个；
- 步骤2:对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；
- 步骤3:针对所有的元素重复以上的步骤，除了最后一个；
- 步骤4:重复步骤1~3，直到排序完成。

### 动图演示
![image](https://pic.leetcode-cn.com/bd63967bb063b11f3bac8e311e5b64abbdbf1e35fa2cad7b41ba4b59357a5a16-file_1581487026615)

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
let sortArray = function(nums) {
  let count = 0, sorted = true
  for(let i = nums.length - 1;i > 0;i--) {
    for(let j = 0;j < i;j++) {
      count++
      if (nums[j] > nums[j + 1]) {
        let temp = nums[j]
        nums[j] = nums[j + 1]
        nums[j + 1] = temp
        sorted = false
      }
    }
    if (sorted) {
      break
    }
  }
  console.log(count)
  return nums
};
```

### 时间复杂度分析

最好情况：数组本身就是有序的，执行一次内层循环就可以，T(n) = O(n)

最坏情况：数组本身是倒序的，T(n) = O(n^2)

平均情况：T(n) = O(n^2)