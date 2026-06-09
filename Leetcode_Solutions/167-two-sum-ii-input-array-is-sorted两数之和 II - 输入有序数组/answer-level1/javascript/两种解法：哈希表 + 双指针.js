
#### 解法一：牺牲空间，换取时间，利用哈希表

时间复杂度：O(n)，空间复杂度：O(n)

没有利用**有序数组**这个条件

```js
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
	let map = new Map();
	for (let i = 0; i <= numbers.length - 1; i++) {
		let index1 = map.get(target - numbers[i]);
        // index1可能是0，所以下面的if判断不能写成 if(index1)
		if (index1 !== undefined) {
			return [index1 + 1, i + 1];
		} else {
			map.set(numbers[i], i);
		}
	}
	return;
};
```

#### 解法二：双指针

时间复杂度：O(n)，空间复杂度：O(1)

```js
var twoSum = function(numbers, target) {
	let i = 0;
	let j = numbers.length - 1;
	while (i < j) {
		if (numbers[i] + numbers[j] === target) {
			return [i + 1, j + 1];
		} else if (numbers[i] + numbers[j] < target) {
			i++;
		} else {
			j--;
		}
	}
};
```
