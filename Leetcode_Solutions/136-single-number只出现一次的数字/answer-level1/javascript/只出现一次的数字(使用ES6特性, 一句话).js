# 异或 与 reduce
```
var singleNumber = function (nums) {
	return nums.reduce((acc, cur) => acc^cur)
}
```
# 2(a+b+c)-(a+b+c) = c 与reduce
```
var singleNumber = function (nums) {
	return [...new Set(nums)].reduce((acc, cur) =>  acc+cur) * 2 - nums.reduce((a,b) => a+b)
}
```

