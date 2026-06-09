[TOC]
# 前端与算法 leetcode 344. 反转字符串
---

## 题目描述
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

 

示例 1：
```
输入：["h","e","l","l","o"]
输出：["o","l","l","e","h"]
```
示例 2：
```
输入：["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]
```
[344. 反转字符串](https://leetcode-cn.com/problems/reverse-string)

## 概要
用s.reverse()的童鞋就不要嚣张了,项目中可以这样做,但是算法题中不建议这样哈
## 提示
双指针,递归
## 解析

### 解法一:双指针
定义头尾两个指针,只要他们还没有重合就交换指针指向的字符
### 解法二:递归
取字符串长度的一半,随后从字符串中间开始交换,直到初值为0
## 算法

```js
/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var reverseString = function (s) {
  // 双指针
  if (s.length > 0) {
    let [i, j] = [0, s.length - 1];
    while (i < j) {
      [s[i], s[j]] = [s[j], s[i]];
      i++;
      j--;
    }
  }
  // 递归
  // const swap = (start, s) => {
  //   if (start > 0) {
  //     [s[start - 1], s[s.length - start]] = [s[s.length - start], s[start - 1]];
  //     swap(--start, s);
  //   }
  // };
  // swap(~~(s.length / 2), s);
};
```

## 传入测试用例的运行结果

```sh
input:['h', 'e', 'l', 'l', 'o']
output:[ 'o', 'l', 'l', 'e', 'h' ]
```

## 执行结果

```
执行用时 :120 ms, 在所有 javascript 提交中击败了98.62%的用户
内存消耗 :47.3 MB, 在所有 javascript 提交中击败了10.98%
的用户
```

### GitHub仓库

[344. 反转字符串](https://github.com/moshuying/AlgorithmAndBlog)
### 查看更多

[查看更多题解](http://sfau.lt/bPbzVVJ)