### 解题思路
空间复杂度 O(1);
时间复杂夫 O(m+n);

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    let p = m + n - 1;
    let p1 = m-1;
    let p2 = n-1;
    while(p1 >= 0 && p2 >= 0){
        nums1[p--] = nums1[p1] < nums2[p2] ? nums2[p2--] : nums1[p1--]
    }
    if(p2 >= 0){
        nums1.splice(0, p2+1);
        while(p2 >= 0){
            nums1.unshift(nums2[p2])
            p2--;
        }
    }
};


```