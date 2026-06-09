### 解题思路
1. 排序词中字母
2. 找到相同的排序然后输出

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    let result = {};
    strs.forEach((str) => {
    	let sorted = str.split('').sort();
    	if (result.hasOwnProperty(sorted))
    		result[sorted].push(str);
    	else
    		result[sorted] = [str];
    });
    return Object.values(result);
};

```

	这道题开始被我想复杂了，我以为是把所用字母相同的字符串排序，
	如果是那样，排序前还要先去除重复的