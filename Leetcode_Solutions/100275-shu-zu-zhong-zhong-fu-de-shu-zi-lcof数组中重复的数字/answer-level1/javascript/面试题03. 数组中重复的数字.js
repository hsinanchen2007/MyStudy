### 解题思路
又get到一个find方法（单次查找，找到一次就结束），美滋滋

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
return nums.find(function(ele,index){
		nums.splice(index,1,null);
		return nums.indexOf(ele) !== -1

	})
};


```