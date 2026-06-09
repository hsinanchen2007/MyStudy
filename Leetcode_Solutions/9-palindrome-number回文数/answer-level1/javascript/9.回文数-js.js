# 9.回文数

https://leetcode-cn.com/problems/palindrome-number/

## 分析

- 整数
- 个位数 true，负数 false
- 末位是 0，回文后首位是 0，不符合，false

## 解

### 1.转成字符串

- 转成字符串
- 反向取值后是否等于原始值

```js
const isPalindrome = function (x) {
  if (x >= 0 && x <= 9) return true
  if (x < 0 || x % 10 === 0) return false

  const str = String(x)
  const len = str.length
  let i = len - 1
  let reStr = ''

  while (i >= 0) {
    reStr += str[i]
    i--
  }

  const res = str === reStr
  return res
}
```

### 2.取余数，反向运算

参考[7.整数反转](../7.reverse/note.md)

- 取余数，mod=x%10，将上一次的结果\*10+mod，作为下一次循环的起始值
- 比较反转后的值和原始值

```js
const isPalindrome = function (x) {
  if (x >= 0 && x <= 9) return true
  if (x < 0 || x % 10 === 0) return false

  let old = x
  let n = 0

  while (old !== 0) {
    const mod = old % 10
    old = parseInt(old / 10)
    n = n * 10 + mod
  }

  const res = x === n
  return res
}
```

### 3.反向运算，只算一半

回文，前半和后半相等，只用算长度的一半

- 需要判断运算到长度的一半
- 转成字符串获取长度/2
- 反向运算同时，获取正向从 0 开始的值，反向运算长度=正常获取长度
- 比较正反两值

```js
const isPalindrome = function (x) {
  if (x >= 0 && x <= 9) return true
  if (x < 0 || x % 10 === 0) return false

  const str = String(x)
  let len = str.length
  const end = len / 2
  let i = len - 1

  let old = x
  let n = 0

  let j = 0
  let m = ''

  while (old !== 0 && i >= end) {
    const mod = old % 10
    old = parseInt(old / 10)
    n = n * 10 + mod
    m += str[j]
    i--
    j++
  }

  const res = +m === n
  return res
}
```

### 4.前后两值判断是否取了一半

用字符串长度判断还是不够给力啊。。  
官方题解给出的判断方法是 `原始值/10 < 反转值，则已经取了一半`，为什么呢。。。

> 长度=偶数：一半的时候 原始=反转，1221 -> 一半的时候，原始值已经变为 12，反转值也是，x=reverse
> 长度=奇数：忽略 中位数，最后 /10 减掉，12321 -> 原始值=12，反转值=123，12=parseInt(123/10)，x=parseInt(reverse/10)
> 所以，while 的条件是 x>reverse
> 但是，最后的相等判断需要两个条件，x=r | x=r/10

- T **_O(logn)_**
- S **_O(1)_**

```js
const isPalindrome = function (x) {
  if (x >= 0 && x <= 9) return true
  if (x < 0 || x % 10 === 0) return false

  let old = x
  let n = 0

  while (old > n) {
    const mod = old % 10
    old = parseInt(old / 10)
    n = n * 10 + mod
  }
  const res = old === n || old === parseInt(n / 10)
  return res
}
```
