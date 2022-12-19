# 前端与算法 leetcode 28.实现 strStr() 
---
# 题目描述
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:
```
输入: haystack = "hello", needle = "ll"
输出: 2
```
示例 2:
```
输入: haystack = "aaaaa", needle = "bba"
输出: -1
```
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

[28.移除元素](https://leetcode-cn.com/problems/-element/)
# 概要
这道题的意义是实现一个api,不是调api,尽管很多时候api的速度比我们写的快(今天这个我们可以做到和indexOf一样快),但我们还是要去了解api内实现的原理,在我们所熟悉的v8引擎中,indexOf使用了kmp和bm两种算法,在主串长度小于7时使用kmp,大于7的时候使用bm,bf咱就不说了哈,那个其实就是爆破算法,
# 提示
数据结构,kmp,bm
# 解析
kmp算法的核心其实就是动态规划,明确了next数组的含义,就能知道该如何推算了,关于KMP算法的解析已经烂大街了,随便一搜就能获得一大把,认真看看就能知道原理了,有空的话,建议手推几遍,有助于加深记忆(背题并不可耻,真的)

### 算法
经典算法的js实现
```js
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
const strStr = (haystack, needle) => {
  if (needle === '') return 0
  let [i, j] = [0, 0]
  const next = []
  const nextfuc = (p, next) => {
    next[0] = -1
    let [j, k] = [0, -1]
    while (j < p.length - 1) {
      if (k === -1 || p[j] === p[k]) {
        if (p[++j] === p[++k]) {
          next[j] = next[k]
        } else {
          next[j] = k
        }
      } else {
        k = next[k]
      }
    }
  }
  nextfuc(needle, next)
  while (i < haystack.length && j < needle.length) {
    if (j === -1 || haystack[i] === needle[j]) {
      i++
      j++
    } else {
      j = next[j]
    }
  }
  if (j === needle.length) {
    return i - j
  } else {
    return -1
  }
}


```
传入`aacabcaacd`和`aacd`的运行结果
```sh
6
```
执行结果
```sh
执行用时 :60 ms, 在所有 javascript 提交中击败了95.66% 的用户
内存消耗 :33.7 MB, 在所有 javascript 提交中击败了33.58%的用户
```
## GitHub仓库

[1. 两数之和](https://github.com/moshuying/leetcode-cn/)