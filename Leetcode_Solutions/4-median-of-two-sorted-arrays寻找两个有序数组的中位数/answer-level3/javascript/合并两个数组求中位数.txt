### 解题思路
1.拼接两个数组；
2.从小到大排序；
3.求数组中位数。

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    var newArr = nums1.concat(nums2).sort((a,b)=>(a-b))
	var mid = parseInt(newArr.length/2)
	if(newArr.length%2){
		return newArr[mid]
	}
	return (newArr[mid-1]+newArr[mid])/2
};

```