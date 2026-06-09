### 解题思路
此处撰写解题思路
先将两数组排序，然后根据两数组长度判断，中位数取一个还是两个平均值，返回结果。
### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    let len1 = nums1.length;
    let len2 = nums2.length;
    let middle;
    let flag;
    if ((len1 + len2) % 2 === 0) {
        middle = parseInt((len1+len2)/2);
        flag = 0;
    } else {
        middle = parseInt((len1+len2)/2) + 1;
        flag = 1;
    }
    let i=0, j=0;
    let arr = [];
    while(i < len1 && j < len2) {
        if (nums1[i] < nums2[j]) {
            arr.push(nums1[i]);
            i++;
        } else {
            arr.push(nums2[j]);
            j++;
        }
    }
    if (i === len1) {
        arr = arr.concat(nums2.slice(j));
    }

    if (j === len2) {
        arr = arr.concat(nums1.slice(i));
    }

    if (flag === 0) {
        return parseFloat((arr[middle-1] + arr[middle]) / 2);
    } else {
        return arr[middle-1];
    }
};
```