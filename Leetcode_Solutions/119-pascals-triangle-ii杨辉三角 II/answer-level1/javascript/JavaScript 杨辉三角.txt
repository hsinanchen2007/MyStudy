### 解题思路
自己还没完全理解，看的大神思路
### 代码

```javascript
/**
 * @param {number} rowIndex
 * @return {number[]}
 */
var getRow = function(rowIndex) {
    let resultArr = [1];
	for (let i = 0; i < rowIndex; i++) {
		resultArr.unshift(0);
		for (let j = 0; j < i + 1; j++) {
			resultArr[j] = resultArr[j] + resultArr[j + 1];
		}
	}
	return resultArr;
};
```