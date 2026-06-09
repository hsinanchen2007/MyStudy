主要这里要改变的是nums1，作为函数的参数，js属于值传递，所以在函数里面的数组的方法得改变数组本身，也就是说不能构造出一个新的数组，最后让nums1指向它，这样其实最后nums1指向的原数组并没有改变，而我们恰恰要改变的是原数组。所以应该使用一些可以改变数组本身的方法，如`Array.push`、`Array.splice`这些  
以下是我的思路
```javaScript
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    let count1 = 0
    let count2 = 0
    let len = nums1.length
    while(count1 < m && count2 < n) {
        if(nums1[count1] > nums2[count2]) {
            nums1.push(nums2[count2++])
        } else {
            nums1.push(nums1[count1++])
        }
    }
       
    if(count1 < m) {
        nums1.splice(nums1.length, 0, ...nums1.slice(count1, m))
    }
    
    if(count2 < n) {
        nums1.splice(nums1.length, 0, ...nums2.slice(count2, n))
    }
    
     nums1.splice(0,len)
};
```
