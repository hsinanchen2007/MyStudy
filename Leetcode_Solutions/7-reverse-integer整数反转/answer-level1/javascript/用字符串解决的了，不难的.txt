### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let str
	if (x < 0) {
	    str = (-x).toString()
	} else {
		str = x.toString()
	}
	str = str.split('').reverse().join('')
	if(str.length>10 || str.length === 10 && str > (x<0?"2147483648":"2147483647")){
		return 0 
	}
			
	if(x<0){
		x = -str
	}else{
		x = +str
	}
	return x
};
```