```javascript []
var tribonacci = function (n) {
	let map = new Map([[0, 0], [1, 1], [2, 1]])
	return cal_tribonacci(map, n)
};
var cal_tribonacci = function (map, n) {
	if (!map.has(n)) map.set(n, cal_tribonacci(map,n - 1) + cal_tribonacci(map,n - 2) + cal_tribonacci(map,n - 3))
	return map.get(n)
}
```

