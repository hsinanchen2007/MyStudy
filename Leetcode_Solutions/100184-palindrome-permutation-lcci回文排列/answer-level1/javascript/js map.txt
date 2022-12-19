### 解题思路
把字母存入map中，遍历map，如果map的长度为1，则直接返回true，若回文，只能存在一个字母的个数为奇数。如果存在两个及以上返回false


### 代码
![image.png](https://pic.leetcode-cn.com/ea58cc791a345e66107135270c7d4aa6fb85d09820d34740e2a23b169a967615-image.png)

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var canPermutePalindrome = function(s) {
    var map = new Map();
	s.split('').map((v) => {
		if (map.get(v)) {
			map.set(v, map.get(v) + 1);
		} else {
			map.set(v, 1);
		}
	});
	
	var flag = 1;
	if (map.length == 1) {
		return true;
	} else {
		map.forEach((value, key) => {
		
			value % 2 == 0 ? '' : flag--;
		});
		
		if (flag < 0) {
			return false;
		}
	}
	return true;
};
```