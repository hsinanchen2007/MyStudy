1、暴力法
遍历所有结果，会超时
```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let n = s.length;
    let ans = 0;
    for(let i = 0; i < n; i++) {
        for(let j = i +1; j <= n; j++) {
            if (allUnique(s, i, j)) ans = Math.max(ans, j - i);
        }
    }
    return ans;
};
const allUnique = function(s,i, j) { // 利用哈希表存储字符串，有重复的则返回false，没有则返回true
    let map = new Map();
    for(let n = i; i < j; i++) {
        if(map.has(s[i])) return false;
        map.set(s[i], true);
    }
    return true;
}
```
时间复杂度: O(n^3);
空间复杂度: O(n)

2、滑动窗口
```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let n = s.length;
    let ans = 0;
    let start = 0;
    let map = new Map();
    for(let end = 0; end < n; end++) {
        if(map.has(s[end])) {
            start = Math.max(map.get(s[end]),start); // 保证这里拿到的是最新的开始地方
        }
        ans = Math.max(ans,end - start + 1);
        map.set(s[end],end+1);
    }
    return ans;
};
```
时间复杂度: O(n)
空间复杂度: O(n)