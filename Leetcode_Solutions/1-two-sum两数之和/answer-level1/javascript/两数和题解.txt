### 解题思路
两层循环，挨个查找，找到就推入数组，返回。

### 代码

```javascript
/**twoSum
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
	var result = [];
	for (var i = 0; i < nums.length; i++) {
	    for (var j = i + 1; j < nums.length; j++) {
			if (nums[i] + nums[j] === target) {
				result.push(i);
				result.push(j);
                return result;
			}
		}
	}
};
var arr = [2, 7, 11, 15];
var number = 9;
var result = twoSum(arr, number);
console.log(result);
```