先偷个懒吧？

```
var addBinary = function(a, b) {
    let sum = parseInt(a, 2) + parseInt(b, 2)
    return sum.toString(2)
};
```
测试用例用长度 99 的字符串，分分钟教做人...

那就逐位相加吧，这样换个..

```
var addBinary = function(a, b) {
	let aa = a.split('').reverse()
	let bb = b.split('').reverse()
	let prefix = 0
    
    // 确保遍历的是长数组
    if (aa.length < bb.length) [aa, bb] = [bb, aa]
    
	let res = aa.map((n, i) => {
		let num = (bb[i] ? parseInt(bb[i]) : 0) + prefix + parseInt(n)
		prefix = num >= 2 ? 1 : 0
		return num % 2
	})
	if (1 === prefix) res.push(1)
	return res.reverse().join('')
};
```