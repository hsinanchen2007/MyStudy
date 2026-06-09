### 解题思路
1. 合并数组，不需要去重
2. 判断数组个数是奇数还是偶数，如果是奇数直接取中间序号对应的值，如果是偶数，取中间序号的两个值算平均数
3. 注意，给定数组是有序的，合并后的数组不一定是有序的，需要手动sort，并且要考虑数组中有负数的情况
### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    let link = nums1.concat(nums2).sort((a, b) => a - b )
    let isOdd = link.length%2 !== 0;

    if(isOdd){
        return link[Math.ceil(link.length/2) -1]
    }else{
        return ( link[link.length/2 -1] + link[link.length/2] )/2
    }
};
```