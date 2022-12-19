### 解题思路
不跑了越跑越慢 开始还能 80ms现在都120ms了，
思路很简单吧，就字符串不断的往上加，如果遇到重复的直接截断
### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s, m = 0, t = '') { // 多加了 m, t 两个变量
    for (let n of s) { // for of ，不做解释
        const l = t.indexOf(n); // indexOf 不做解释
        if (l >= 0){
            t = t.substring(l + 1); // substring 截取从重复位置的下标 + 1
        }
        t += n;
        // 进行判断是否最大
        const L = t.length; if (L > m) m = L;
    }
    return m;
};
```