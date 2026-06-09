### 解题思路
滑动窗口问题

用左右两个指针表示当前的滑动窗口

1. 初始化：left = 0，right = 0。
2. 不断右移 right，直到当前窗口包含了 T 中的所有字母
3. 此时不断右移 left，尽可能缩小当前窗口
4. 当当前窗口不满足包含 T 所有字母的条件时，进行操作 2
5. 当 right 到达 s 的末尾时，结束

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
    const needs = {}, currentWindow = {};
    for (let i = 0; i < t.length; ++i) {
        needs[t[i]] = needs[t[i]] ? needs[t[i]] + 1 : 1;
    }
    let left = 0, right = 0, matches = 0, res = s, isFound = false;
    while (right < s.length) {
        const c = s[right];
        if (needs[c]) {
            currentWindow[c] = currentWindow[c] ? currentWindow[c] + 1 : 1;
            if (currentWindow[c] === needs[c]) {
                ++matches;
            } 
        }
        ++right;

        while (matches === Object.keys(needs).length) {
            isFound = true;
            res = (right - left) < res.length ? s.slice(left, right) : res;
            const leftChar = s[left];
            if (needs[leftChar]) {
                currentWindow[leftChar] = currentWindow[leftChar] - 1;
                if (currentWindow[leftChar] < needs[leftChar]) {
                    --matches;
                }
            }
            ++left;
        }
    }
    return isFound ? res : '';
};
```

### 复杂度分析
- 时间复杂度 O(N)
- 空间复杂度 O(1)