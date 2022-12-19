
## 暴力

```javascript
var dailyTemperatures = function(T) {
	return T.map(function(t, i) {
		for (let days = 0; i + days + 1 < T.length ; days++) {
			if (T[i + days + 1] > t){
				return days + 1
			}
		}
		return 0
	})
};
```

时间复杂度O(N^2),空间复杂度O(1)

## 单调递减栈

```javascript
var dailyTemperatures = function(t) {
    let stack = [], ans = new Array(t.length).fill(0)

    for (let i = 0; i< t.length; i++){
        while (stack.length > 0 && t[stack[stack.length-1]] < t[i]){
            let cur = stack.pop()
            ans[cur] = i - cur
        }
        stack.push(i)
    }

    return ans
};
```

时间复杂度O(N),空间复杂度O(N)

欢迎关注[leetcode题解](https://github.com/muyids/leetcode)

[单调栈专题](https://github.com/muyids/leetcode/blob/master/tags/%E5%8D%95%E8%B0%83%E6%A0%88.md) 