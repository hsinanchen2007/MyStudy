```
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
      if (nums1.length > nums2.length) {
        [nums1, nums2] = [nums2, nums1]
      }
      const _num1 = [...new Set(nums1)]
      return _num1.filter(item => nums2.includes(item))
};
```
菜狗一个··没学过什么算法··
我的思路是···
两个传入数组根据length排序（是排参数，确保nums1的length比nums2的小），小的放前面，这样遍历次数最小。
用Set把length小的也就是nums1去重，然后用filter遍历判断元素是否包含在num2中，返回新数组。

