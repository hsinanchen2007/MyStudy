### 解题思路
此处撰写解题思路
找到相应规则
1.判断大到小还是小到大。小到大说明是减。大到小则无脑加



### 代码


```javascript
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function (s) {
	let obj = {
		I: 1,
		V: 5,
		X: 10,
		L: 50,
		C: 100,
		D: 500,
		M: 1000,
	};
	let strarr = s.split('');
	// console.log(strarr);
	let num = 0;
	for (let i = 0; i < strarr.length; i++) {

		if (obj[strarr[i]] < obj[strarr[i + 1]]) {
			// console.log(obj[strarr[i + 1]]);
			// console.log(obj[strarr[i]]);
			// console.log(num);
			num = -obj[strarr[i]] + num;
		} else {
			// console.log(obj[strarr[i]]);
			num += obj[strarr[i]];
		}
		//  M = 1000, CM = 900, XC = 90, IV = 4.
	}
	return num;
};
```