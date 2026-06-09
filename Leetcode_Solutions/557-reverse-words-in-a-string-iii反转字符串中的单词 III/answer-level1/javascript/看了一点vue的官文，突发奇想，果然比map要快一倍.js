### 解题思路
官方文档的v-on的example！！！！
执行用时 :84 ms, 在所有 JavaScript 提交中击败了89.38%的用户
内存消耗 :41 MB, 在所有 JavaScript 提交中击败了97.30%的用户

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    let arr=s.split("").reverse().join("")
    return arr.split(" ").reverse().join(" ")
};
```