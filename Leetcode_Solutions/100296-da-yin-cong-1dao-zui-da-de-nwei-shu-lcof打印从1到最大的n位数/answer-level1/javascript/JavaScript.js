### 解题思路
首先确定最大值即为10^n-1;循环将从1到最大值的数加入到数组中

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var printNumbers = function(n) {
        var a = Math.pow(10,n);
	    var arr = [];
		for(var i = 1;i<a;i++){
			arr.push(i);
		    }
		return arr;
};
```