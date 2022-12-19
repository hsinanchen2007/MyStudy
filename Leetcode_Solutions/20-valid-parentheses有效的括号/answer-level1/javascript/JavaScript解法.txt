### 解题思路
这道题自己没解出来，是看了官方的解答思路才解出来的(没看答案)，利用了堆栈的思想，左右括号必然是成对出现，并且如果出现一个右括号，那么与它相邻的前一个括号必是与之匹配的左括号，否则无效。

那么答案就来了，左括号就push,右括号先判断是否与栈顶的最后一个元素匹配，如果匹配，就将数组的最后一个元素推出栈，如果不匹配，直接返回false，最后判断数组的长度是否为零，为零则表示所有括号对都已匹配成功，是有效字符串。
### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
	const arr = [];
	const leftBracket = ['(', '[', '{'];
	const rightBracket = [')', ']', '}'];
	const brackets = {
		'(': 0,
		'[': 1,
		'{': 2,
		'}': 3,
		']': 4,
		')': 5,
	};
	for (let i = 0; i < s.length; i++) {
        if (leftBracket.includes(s[i])) {
            arr.push(s[i]);
        } else {
            if (i === 0 || brackets[arr[arr.length - 1]] + brackets[s[i]] !== 5) {
                return false;
            } else {
                arr.pop();
            }
        }
	}
	return arr.length === 0;
};
```