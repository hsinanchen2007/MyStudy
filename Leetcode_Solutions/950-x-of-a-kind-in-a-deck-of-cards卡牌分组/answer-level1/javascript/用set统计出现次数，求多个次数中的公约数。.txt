### 解题思路
用set统计出现次数，求多个次数中的公约数。

### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function(deck) {
	if (deck.length < 2) return false;
	let map = new Map();
	for (let i = 0; i < deck.length; i++) {
		const item = deck[i];
		map.set(item, map.get(item) ? map.get(item) + 1 : 1);
	}

	const flag = [];
	var arr = [];
	for (let [ key, value ] of map) {
		arr.push(value);
	}
	for (let i = 0; i + 1 < arr.length; i++) {
		arr[i + 1] = gcd(arr[i], arr[i + 1]);
	}
	if (arr[arr.length - 1] == 1) return false;
	return true;
};
var gcd = function(a, b) {
	if (b == 0) return a;
	return gcd(b, a % b);
};
```