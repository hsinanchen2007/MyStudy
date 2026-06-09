我以为的解法
```js
var swapNumbers = function(numbers) {
	numbers[0] = numbers[0] - numbers[1];
	numbers[1] = numbers[1] + numbers[0];
	numbers[0] = numbers[1] - numbers[0];
    return numbers
};
```
大神的解法：
```js
var swapNumbers = function(numbers) {
	return [numbers[1],numbers[0]]
};
```

