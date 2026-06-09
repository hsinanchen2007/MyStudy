### 解题思路
直接利用数组API暴力解题。。。

### 代码

```javascript
/**
 * @param {number[][]} items
 * @return {number[][]}
 */
var highFive = function(items) {
    // 拿到所有id
    const ids = [... new Set(items.map(aa => aa[0]))];
    const scores = [];
    for (let i = 0; i < ids.length; i++) {
        let currItem = items.filter(item => item[0] === ids[i]);
		const score = currItem.map(aa => aa[1]).sort((a,b) => b - a);
        let prefix = score.slice(0, 5);
		let sco = prefix.reduce((a ,b) => a + b) / prefix.length;
        sco = Math.floor(sco);
        scores.push(sco);
    }
    const result = scores.map((s, i) => [i + 1, s]);
	return result;
};
```