## 要点
1. 区分有效重复和无效重复
2. 处理末尾不重复情况

### js
```js
var lengthOfLongestSubstring = function (s) {
    let m = new Map();
    let res = 0, counter = 0;
    let iRepeat = -1;
    for (let i = 0, len = s.length; i < len; i++) {
        let c = s[i];
        if (m.has(c) && m.get(c) > iRepeat) {
            iRepeat = m.get(c);
            counter = i - iRepeat;
        } else {
            counter++;
        }
        // res = max(res, counter);
        if (counter > res) {
            res = counter
        }
        m.set(c, i);
    }
    return res
};
```

### golang
```go
func lengthOfLongestSubstring(s string) int {
	indexMap := make([]int, 128)
	var max, start, num int
	for i, c := range s {
		if indexMap[c] > start {
			start = indexMap[c]
		}
		num = i - start + 1
		if max < num {
			max = num
		}

		indexMap[c] = i + 1
	}
	return max
}
```
使用数组记录字符下标借鉴了解题区里一位大神的思路，运行结果惊人！
> Accepted
> - 987/987 cases passed (0 ms)
> - Your runtime beats 100 % of golang submissions
> - Your memory usage beats 93.16 % of golang submissions (2.6 MB)

至于sliding-window，尚待学习。