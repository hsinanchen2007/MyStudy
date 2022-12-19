### 解题思路
此处撰写解题思路
输出的正整数序列至少包含2个数，因此遍历次数最大为target/2 向下取整+1,或者向上取整的值
1、第一层遍历，记录累加的初始值
2、第二层遍历，判断该初始值下有无符合要求的情况
3、有符合情况的值，则通过之前记录的累加初始值，以及第二层遍历的数值，然后新建数组，将符合的值放入数组

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    let ary = []
	let sum = 0
	let length = Math.floor(target/2)+1
	//遍历累加
	for (let i = 1; i <= length; i++) {
		for (let j = i; j <=length; j++){
			sum += j
			if(sum>target){
				sum = 0;
				break;
			} else if(sum===target){
				let ary2 = []
				for (let k = i; k <= j; k++) {
					ary2.push(k)
				}
				ary.push(ary2)
				sum = 0;
				break;
			}
		}
		
	}
	return ary
};
```