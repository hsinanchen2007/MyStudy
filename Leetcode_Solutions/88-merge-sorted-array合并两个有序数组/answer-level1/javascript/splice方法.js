### 解题思路
splice可以用来删除，改变，替换原数组，nums1删除m之后的元素，nums2删除n之后的元素，这时nums1与nums2就符合条件了，将nums2元素添加到nums1,对nums1排序

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function (nums1, m, nums2, n) {
    nums1.splice(m)
    nums2.splice(n)
    nums2.forEach(item => {
        nums1.push(item)
    })
    nums1.sort((a, b) => {
        if (a > b) {
            return 1
        }
        if (a < b) {
            return -1
        }
        if (a === b) {
            return 0

        }
    })
};
```