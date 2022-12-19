### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
	if(x<0) return false
	let y =0,tmp=x;
	while(tmp){
		y = y*10+tmp%10
		tmp = parseInt(tmp/10)
	}
	return x===y ? true : false 
};
```