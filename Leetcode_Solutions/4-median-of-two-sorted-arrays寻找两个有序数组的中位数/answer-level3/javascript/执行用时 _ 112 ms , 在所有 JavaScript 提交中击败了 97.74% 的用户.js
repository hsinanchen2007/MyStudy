### 解题思路
此处撰写解题思路
执行用时 :112 ms, 在所有 JavaScript 提交中击败了97.74%的用户
内存消耗 :39.1 MB, 在所有 JavaScript 提交中击败了89.73%的用户
![image.png](https://pic.leetcode-cn.com/ac7b43c693dd685139b6a95b19370518fb8a3b3f624e319df1a249a51e3f95ca-image.png)
### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
 let numList = [];
    if (nums1.length == 0 || nums2.length == 0) {
        nums1.length ? numList = nums1 : numList = nums2
    } else {

        while (nums1[0] != undefined && nums2[0] != undefined) {

            if (nums1[0] < nums2[0]) {
                numList.push(nums1[0])
                nums1.shift();
            } else {
                numList.push(nums2[0])
                nums2.shift();
            }
        }

        nums1[0] == undefined ?  numList=numList.concat(nums2): numList=numList.concat(nums1)
    }


    if (numList.length % 2 == 0) {
        return (numList[numList.length / 2] + numList[numList.length / 2 - 1]) / 2;
    } else {
        return numList[(numList.length - 1) / 2]
    }


};
```