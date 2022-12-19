### 解题思路
把字符串转换为数组，用sort排序后再转换为字符串，进行比较。
用循环的方法需要判断元素类型和重复次数，相对比较复杂了。

### 代码

```javascript
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var CheckPermutation = function(s1, s2) {
    return s1.split('').sort().toString()===s2.split('').sort().toString();
};
```