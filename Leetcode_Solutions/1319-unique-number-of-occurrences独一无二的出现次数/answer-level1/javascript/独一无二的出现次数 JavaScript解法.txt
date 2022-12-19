### 解题思路
新建一个map，遍历数组，如果map已有这个元素，则将这个元素的值加1，如果没有，则将这个元素的值设为1。遍历完之后，得到的是一个键为数组中的某个数字，值为这个数字在数组中出现的数字的map对象。

之后取map对象的values，将它的长度和去重后的长度比较，则可以知道这个数组是否有重复的元素。

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {boolean}
 */
var uniqueOccurrences = function(arr) {
 const maps = new Map();
	for (let i = 0; i < arr.length; i++) {
			if (maps.has(arr[i])) {
					maps.set(arr[i], maps.get(arr[i]) + 1);
			} else {
				maps.set(arr[i], 1);
			}
	}
	const values = [...maps.values()];
	return values.length === [...new Set(values)].length;
};
```