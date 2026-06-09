#### 思路
1. 用一个队列`q = []`来维护无重复字符串；
2. 遍历`s='abcdbcd'`，
3. 如果当前元素不在`q`中，入队，例如：`q = [a, b, c, d]`；
4. 如果当前元素在`q`中，例如：`s[4] = 'b'`，已经在`q`中存在了，将`q`中`b`之前（包含`b`）的元素出队，计算每次操作前的最大长度；
#### 代码
```
var lengthOfLongestSubstring = function(s) {
    let q = [];
    let len = 0;
    for (let i = 0; i < s.length; i++) {
        // 不重复元素入队
        if (q.includes(s[i])) {
            // 保存当前最大长度
            len = Math.max(len, q.length);
            // 将队列中，重复元素和它之前的元素出队
            q.splice(0, q.indexOf(s[i]) + 1);
        }
        // 将当前元素入队
        q.push(s[i])
    }
    return Math.max(len, q.length);
};
```
