### 解题思路
trim() 清除前后空格
split() 正则匹配多个连续空格
reverse() 翻转数组
join() 数组转字符串

虽然这道题是想考察旋转数组的吧
[189旋转数组](https://leetcode-cn.com/problems/rotate-array/)

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.trim().split(/\s+/).reverse().join(" ");
};
```