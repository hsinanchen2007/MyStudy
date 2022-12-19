### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    if(nums1.length > nums2.length){
        let tmp = nums1;
        nums1 = nums2;
        nums2 = tmp;
    };
    let set = new Set(nums1);
    let arr = [];

    for(let item of set){
        if(nums2.indexOf(item)>-1) arr.push(item)
    }

    return arr;
};
```