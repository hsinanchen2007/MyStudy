### 解题思路
1. 通过映射表 map 存储字符出现的次数
2. 只要一个字符出现 2 次，就视为可以组成回文，cnt += 2
3. 最后如果 cnt 的长度就是 s 的长度，表示整个字符串都可以形成回文，因为 cnt +=2，因此 cnt 为偶数
4. 如果 cnt 长度与 s 的长度不相等，则随便取一个数作为中位数，形成 cnt + 1 长度的回文

### 复杂度分析

时间复杂度：O(n)，循环次数为 s 的长度。
空间复杂度：O(n)，最长有 s 的长度的个数的元素

### 代码

```js
/**
 * @param {string} s
 * @return {number}
 */
const longestPalindrome = function (s) {
    let map = {};
    let cnt = 0;
    for (let i = 0; i < s.length; i++) {
        let char = s[i];
        if (!map[char]) {
            map[char] = 1;
        } else {
            map[char] = 0;
            cnt += 2;
        }
    }
    return cnt === s.length ? cnt : cnt + 1;
};
```
