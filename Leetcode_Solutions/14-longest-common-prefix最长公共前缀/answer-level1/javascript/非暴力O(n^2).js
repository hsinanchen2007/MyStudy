### 解题思路
执行用时 :60 ms, 在所有 JavaScript 提交中击败了94.48%的用户
内存消耗 :34 MB, 在所有 JavaScript 提交中击败了90.46%的用户
非暴力O(n^2)

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
	let start = 0;
	let next = 1;
	let prefix = "";
	if(strs.length < 1) return "";
	if(strs.length === 1) return strs[0];
	if(strs[0].length > strs[1].length) {
		start = 1;
		next = 0;
	}
	prefix = callBack(strs[start], strs[next]);
	if (prefix === '') return prefix;
	for(let i = 2; i < strs.length; i++) {
		const str = strs[i].slice(0, prefix.length);
		if (prefix === '') return prefix;
		if (str !== prefix) {
			prefix = callBack(str, prefix)
		}
	}
	return prefix
};

function callBack(value, nextValue) {
	let prefix = "";
	for(let i = 0; i < value.length; i++) {
		if(value[i] === nextValue[i]) {
			prefix += value[i];
		} else {
			return prefix
		}
	}
	return prefix;
}
```