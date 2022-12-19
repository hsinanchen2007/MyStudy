### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    var nums3 = [];
    //都不为空时，处理合并
    while(nums1.length && nums2.length){
        let tmp = 0;
        if(nums1[0] > nums2[0]) tmp = nums2.shift();
        else tmp = nums1.shift();
        nums3.push(tmp);
    }
    //连接剩下的元素
    if(nums1.length) nums3 = nums3.concat(nums1);
    if(nums2.length) nums3 = nums3.concat(nums2);
    //求合并后数组中位数
    if(nums3.length%2 === 0) return (nums3[nums3.length >> 1] + nums3[(nums3.length >> 1) - 1]).toFixed(1)/2.0;
    return nums3[nums3.length >> 1];
};
```