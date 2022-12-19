大家勉强看吧， 

```
var numDistinct = function (s, t) {
    if (!s || !t) {
      return 0
    }

	// map 用来储存t中出现过的字符
	// obj 用来计算匹配上的字符数量
	 
	let map = {}
	let obj = {
		"": 1
	}
	for (let i = 0; i < t.length; i++) {
		if (map[t[i]]) {
			map[t[i]].push(i)
		} else {
			map[t[i]] = [i]
		}
	}
	for (let i = 0; i < s.length; i++) {
		// 如果字符未在map中则不能匹配直接跳过
		if (!map[s[i]]) {
			continue
		}
		// 找到map中字符出现过的位置遍历所有位置
		for (let j = map[s[i]].length - 1; j > -1; j--) {
			let item = map[s[i]][j]
			//如果obj中不存在当前字符的上一个字符的时候则啥也不做
			// 如果 匹配 abc中的c , 则 ab 必须出现在 obj 中
			if (obj[t.slice(0, item)]) {
				//查看匹配字符串是否出现过  若 ab存在， 切当前字符为c ，则查看abc是否存在
				// 若存在则加上 ab的的数值，不存在则设置为ab的数值
				// 为什么加ab的值是应为之前abc的所有组合已经确定，而当前的c可以重新和ab组成新的abc 所以加上
				if (obj[t.slice(0, item + 1)]) {
					obj[t.slice(0, item + 1)] += obj[t.slice(0, item)]
				} else {
					obj[t.slice(0, item + 1)] = obj[t.slice(0, item)]
				}
			}
		}
	}
	return obj[t] || 0
};
```
从时间复杂度和空间复杂度来计算
常规是优于O(m * n)
最坏的情况是O(m * n)

