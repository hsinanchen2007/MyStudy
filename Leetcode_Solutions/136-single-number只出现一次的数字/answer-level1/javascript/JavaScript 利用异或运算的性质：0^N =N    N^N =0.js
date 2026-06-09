### 解题思路
异或运算的性值：0^N = N    N^N = 0
所以出现偶数次得数异或后为0；
遍历数组，与0异或剩下的数字即为出现奇数次的数

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(arr) {
        var eor = 0;
		for(var i = 0;i<arr.length;i++){
			eor ^= arr[i];
		}
		return eor;
};
```