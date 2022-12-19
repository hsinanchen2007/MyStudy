[TOC]
# 前端与算法 leetcode 387. 字符串中的第一个唯一字符
---

## 题目描述
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:
```
s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
 
```
注意事项：您可以假定该字符串只包含小写字母。

[387. 字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string)

## 概要

## 提示
双for循环遍历一下
## 解析

### 解法一:双循环
最简单的解法就是双for循环遍历一下所有字符的出现次数存在Map里,然根据map中出现次数仅为一次的字符返回其下标即可
### 解法二:Set法单循环
构建一个Set对象,使用`s.include(s[i],i+1)`判断`i+1`后面是否出现改字符和`set.has(s[i])`判断之前是否有这个字符即可

## 算法

```js
/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function (s) {
  // 解法二
  if (s === '' || s.length < 1) {return -1;}
  let set = new Set();
  for (let i = 0 ;i < s.length;i++) {
    // includes第二个参数可选。从当前字符串的哪个索引位置开始搜寻子字符串，默认值为0。
    if (!s.includes(s[i], i + 1) && !set.has(s[i])) {
      return i;
    } else {
      set.add(s[i]);
    }
  }
  return -1;
  // 解法一
  // if (s === '' || s.length < 1) {return -1;}
  // let map = {};
  // for (let i = 0 ;i < s.length;i++) {
  //   map[s[i]] === undefined ? map[s[i]] = 0 : map[s[i]]++;
  // }
  // for (const key in map) {
  //   if (map[key] === 0) {
  //     return s.indexOf(key);
  //   }
  // }
  // return -1;
};

```

## 传入测试用例的运行结果

```sh
input:asdfagsdfasdf
output:5
```

## 执行结果

```
执行用时 :92 ms, 在所有 javascript 提交中击败了93.73%的用户
内存消耗 :37.9 MB, 在所有 javascript 提交中击败了48.47%的用户
```


### GitHub仓库

[344. 反转字符串](https://github.com/moshuying/AlgorithmAndBlog)

### 查看更多

[查看更多题解](http://sfau.lt/bPbzVVJ)