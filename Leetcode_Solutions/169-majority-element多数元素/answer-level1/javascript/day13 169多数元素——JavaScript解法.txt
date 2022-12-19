### 解题思路
根据定义：多数元素是指在数组中出现次数大于[n/2]的元素。
所以当把数组排序后，其中间位置的数必定是多数元素。
所以主要问题就是排序：可以选择数组自带的方法进行排序

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums){
		nums.sort(function sort1(a,b){
			return a-b;
		})
		return nums[Math.floor(nums.length/2)];
			
};
```