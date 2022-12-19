### 解题思路

用了非常简单的javascript中的原型方法，将两个数组连接起来，然后进行排序，之后根据奇偶数分别求即可。
### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    let arr = nums1.concat(nums2);
    arr = arr.sort((a,b)=>(a-b));
    if(arr.length%2){
        return arr[parseInt(arr.length/2)]
    }else{
        return (arr[parseInt(arr.length/2)] + arr[parseInt(arr.length/2)-1])/2
    }
};
```