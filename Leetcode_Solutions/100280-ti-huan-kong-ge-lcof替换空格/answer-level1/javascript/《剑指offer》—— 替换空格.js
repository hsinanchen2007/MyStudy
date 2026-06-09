[点我看原题](https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/)
[点我看原文](https://juejin.im/post/5e548816518825496f3820d0)

## 题目描述

请实现一个函数，把字符串 ``s`` 中的每个空格替换成"%20"。

## 解题思路

- 使用正则表达式将所有空格替换为 "%20"
- 循环遍历字符串 ``s``，将替换的结果保存到另外一个变量 ``res`` 中 

⚠️注意：正则表达式当中 ``\s`` 表示匹配空格，``g`` 表示全局匹配，如果不熟悉正则表达式，直接去 [MDN](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Guide/Regular_Expressions) 上看一看，多练练就会了。

## 代码

### 正则表达式解法

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var replaceSpace = function(s) {
    return s.replace(/\s/g, '%20')  
};
```

### 循环解法
```javascript
/**
 * @param {string} s
 * @return {string}
 */
var replaceSpace = function(s) {
    let res = ''
    for (let i = 0; i < s.length; i++) {
        if (s.charAt(i) === ' ') {
            res += '%20'
        } else {
            res += s.charAt(i)
        }
    }
    return res
};
```