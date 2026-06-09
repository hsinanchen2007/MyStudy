### 解题思路
前面和其他思路大体一致，先判断数组的和是否能被3整除，能被3整除才能继续下去。

接下来的思路是找到前面i个元素的和等于aver的元素，找到将前面i个元素截取掉，并重置for循环。当flag为2时，表示剩下的元素即为满足和相等的第三个部分。此时退出for循环，判断剩下元素的和是否等于aver即可。但是要先排除剩余元素的长度为0的情况。

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {boolean}
 */
var canThreePartsEqualSum = function(A) {
	const totalSum = A.reduce((x, y) => x + y);
	if ( totalSum % 3 !== 0) return false;
	const aver = totalSum / 3;
	let sum = 0;
	let flag = 0;
	for (let i = 0; i < A.length; i++) {
		sum += A[i];
		if (sum === aver) {
			if (flag === 2) {
				break;
			}
			sum = 0;
			flag += 1;
			A.splice(0, i + 1);
			i = -1;
		}
	}
    if (A.length === 0) return false;
	const last = A.reduce((x,y) => x+y);
	return last === aver;
};
```

### 附上js高赞解法
```javascript
var canThreePartsEqualSum = function(A) {
    let sum = A.reduce((acc,cur)=>acc+cur) //sum数组之和
    let temp = 0   //temp累加
    let cnt = 0   //cnt计数
    for(let i=0;i<A.length;i++){
        temp += A[i] 
        if(temp == sum/3){  
            cnt++   
            temp = 0
        }
		if (sum === 3) return true;
    }
    return false
};
```
