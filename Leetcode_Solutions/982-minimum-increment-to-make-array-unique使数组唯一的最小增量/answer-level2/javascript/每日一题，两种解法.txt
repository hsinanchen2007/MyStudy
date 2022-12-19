## 解题思路

1. 数组  
  排序  
  遍历，如果当前的数小于或等于前一个数，说明要加  
  计算当前数和前一个数的差值再加 1，就实现了当前数比前一个数多 1
```bash
var minIncrementForUnique = function (A) {
	A = A.sort((a, b) => a - b)
	// console.log(A);
	var count = 0
	for (let i = 1; i < A.length; i++) {
		if (A[i] <= A[i - 1]) {
			let n = A[i - 1] + 1 - A[i]
			A[i] += n
			count += n
		}
	}
	return count
};
console.log(minIncrementForUnique([3, 2, 1, 2, 1, 7]))

```
2. Map  
	新建一个Map，数值作为key  
	如果该数值第一次出现，则存入Map中  否则加 1  
	结果执行超时
```bash
var minIncrementForUnique = function (A) {
	let count = 0
	let map = new Map()
	for (let num of A) {
		while (map.has(num)) {
			count++
			num++
		}
		map.set(num, true)
	}
	return count
}

console.log(minIncrementForUnique([3, 2, 1, 2, 1, 7]))
```
