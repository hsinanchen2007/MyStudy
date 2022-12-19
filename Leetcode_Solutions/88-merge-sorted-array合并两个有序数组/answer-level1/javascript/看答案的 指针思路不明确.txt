### 解题思路
循环插值很容易想到
后面的函数有点吃力
意义就是 把nums2 放到nums1的前面  注意循环中条件是nums1[i]>nums2[j] 
若nums2循环完 返回就是nums1
若nums2未循环完 返回 nums2未循环的部分  +  num1(截取前面的部分 大小为nums2大小的位置)

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
   let i=m-1,j=n-1;len = m+n-1

    while(i>=0 && j>=0){
        nums1[len--]=nums1[i]>nums2[j]?nums1[i--]:nums2[j--]
    }
    function concatArray(Array1,index1,Array2,index2,length) {
        Array1.splice(index1,length,...Array2.slice(index2,index2+length))
    }
    concatArray(nums1,0,nums2,0,j+1)

};