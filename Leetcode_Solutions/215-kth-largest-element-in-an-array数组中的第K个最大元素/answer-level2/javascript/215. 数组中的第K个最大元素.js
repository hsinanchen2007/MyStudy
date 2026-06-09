思路:
将冒泡排序做了稍微的修改
1. 冒泡排序的原理是遍历n次数组,每次拿出最大值与最后一位交换
2. 本题只需要求到第k个最大值,也就是说我们只需要遍历k次数组就够了
3. 时间复杂度为O(nlogn)
```javascript []
var findKthLargest = function (nums, k) {
  for (let i = nums.length; i > nums.length - k - 1; i--) {
    for (let j = 0; j < i; j++) {
      if (nums[j] > nums[i]) {
        [nums[j], nums[i]] = [nums[i], nums[j]]
      }
    }
  }
  return nums[nums.length - k]
};
```
![image.png](https://pic.leetcode-cn.com/893cb8ad78a2322be92953fdb71011624731c44cc76bcba2e39ae55c950ce376-image.png)

虽然只有24.87%,但我看前排的都是用的sort api.....
行吧...
