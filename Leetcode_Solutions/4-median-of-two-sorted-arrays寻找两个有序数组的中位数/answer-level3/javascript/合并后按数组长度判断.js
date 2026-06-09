### 解题思路
1.合并数组
2.将数组从小到大排序
3.判断合并后数组长度奇偶
4.根据长度奇偶返回不同索引的值
### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    const arr = nums1.concat(nums2).sort((a, b) => a - b)
    const len = arr.length;
    if (len % 2 === 0) {
        return (arr[len / 2 - 1] + arr[len / 2]) / 2
    } else {
        return arr[(len - 1) / 2]
    }
};
```