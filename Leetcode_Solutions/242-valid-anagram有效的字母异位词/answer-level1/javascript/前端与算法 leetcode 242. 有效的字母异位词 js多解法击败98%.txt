[TOC]
# 前端与算法 leetcode 242. 有效的字母异位词
---

## 题目描述
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1:
```
输入: s = "anagram", t = "nagaram"
输出: true
```
示例 2:
```
输入: s = "rat", t = "car"
输出: false
说明:
你可以假设字符串只包含小写字母。
```
进阶:
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

[242. 有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram)

## 概要
判断异位词的方法很多,可以用哈希表,也可以构建26个字符数组判断,还可以根据每个字符出现的次数排序后判断字符串是否相等
## 提示
哈希,数组
## 解析

### 解法一:哈希表
哈希表在本题中表现一般,但看到这题时往往第一时间就能想到这个办法.构建一个HashMap然后统计s中每个单词出现的次数,随后用这个表去判断第t中所有字符出现的次数,一旦字符出现的次数不相等或者没有这个字符就返回false
### 解法二:数组判断字符出现次数
构建一个长度为26的数组然后全部填充0,随后s中的`s[i]`字符出现一次该下标位置的数字就自加一次,`t[i]`对应的下标自减一次,最后的结果中有一个不为0则表示s和t不相等
### 解法三:转换字符串
和解法二思路类似,但其实就是排序后判断字符串是否相等
## 算法

```js
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
  // 哈希法
  // if (s.length !== t.length) {return false;}
  // let map = new Map();
  // for (let i = 0;i < s.length;i++) {
  //   map.get(s[i]) === undefined ? map.set(s[i], 1) : map.set(s[i], map.get(s[i]) + 1);
  // }
  // for (let j = 0;j < t.length;j++) {
  //   if (map.get(t[j]) > 0) {map.set(t[j], (map.get(t[j])) - 1);} else {return false;}
  // }
  // return true;
  // 26个字符法
  if (s.length !== t.length) {return false;}
  let kmap = new Array(26).fill(0);
  for (let i = 0 ;i < s.length;i++) {
    kmap[s[i].charCodeAt(0) - 97]++;
    kmap[t[i].charCodeAt(0) - 97]--;
  }
  for (let i = 0;i < 26;i++) {
    if (kmap[i] !== 0) {return false;}
  }
  return true;
  // 解法三
  // if (s.length !== t.length) return false
  // let o = new Array(26).fill(0)
  // for (let i = 0; i < s.length; i++) {
  //   o[s[i].charCodeAt(0) - 97]++
  // }
  // let p = new Array(26).fill(0)
  // for (let i = 0; i < t.length; i++) {
  //   p[t[i].charCodeAt(0) - 97]++
  // }
  // o = o.toString()
  // p = p.toString()
  // return o === p
};
```

## 传入测试用例的运行结果

```sh
input:"rat","art"
output:true
```

## 执行结果

```
执行用时 :68 ms, 在所有 javascript 提交中击败了98.28%的用户
内存消耗 :35.7 MB, 在所有 javascript 提交中击败了87.50%的用户
```

### GitHub仓库

[242. 有效的字母异位词](https://github.com/moshuying/AlgorithmAndBlog)