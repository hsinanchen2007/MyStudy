## 思路

这个题目的大意是： 给定一个无符号的整数， 返回其用二进制表式的时候的1的个数。

这里用一个trick， 可以轻松求出。 就是`n & (n - 1)` 可以`消除` n 最后的一个1的原理。

> 为什么能消除最后一个1， 其实也比较简单，大家自己想一下

这样我们可以不断进行`n = n & (n - 1)`直到n === 0 ， 说明没有一个1了。
这个时候`我们消除了多少1变成一个1都没有了， 就说明n有多少个1了`。

## 关键点解析

1. `n & (n - 1)` 可以`消除` n 最后的一个1的原理 简化操作

2. bit 运算


## 代码

语言支持：JS, C++，Python

JavaScript Code:

```js
/*
 * @lc app=leetcode id=191 lang=javascript
 *
 */
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
  let count = 0;
  while (n !== 0) {
    n = n & (n - 1);
    count++;
  }

  return count;
};

```

C++ code:

```c++
class Solution {
public:
    int hammingWeight(uint32_t v) {
        auto count = 0;
        while (v != 0) {
            v &= (v - 1);
            ++count;
        }
        return count;
    }
};
```

Python Code:

```python
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = 0
        while n:
            n &= n - 1
            count += 1
        return count
```

## 扩展
可以使用位操作来达到目的。例如8位的整数21:

![](https://pic.leetcode-cn.com/4ff4aa83d67a8b907f9b3fc9a891fb99c4f41a7bb5b800f0c8f4ff8fbe022030.jpg)

C++ Code：
```c++
const uint32_t ODD_BIT_MASK = 0xAAAAAAAA;
const uint32_t EVEN_BIT_MASK = 0x55555555;
const uint32_t ODD_2BIT_MASK = 0xCCCCCCCC;
const uint32_t EVEN_2BIT_MASK = 0x33333333;
const uint32_t ODD_4BIT_MASK = 0xF0F0F0F0;
const uint32_t EVEN_4BIT_MASK = 0x0F0F0F0F;
const uint32_t ODD_8BIT_MASK = 0xFF00FF00;
const uint32_t EVEN_8BIT_MASK = 0x00FF00FF;
const uint32_t ODD_16BIT_MASK = 0xFFFF0000;
const uint32_t EVEN_16BIT_MASK = 0x0000FFFF;

class Solution {
public:

    int hammingWeight(uint32_t v) {
        v = (v & EVEN_BIT_MASK) + ((v & ODD_BIT_MASK) >> 1);
        v = (v & EVEN_2BIT_MASK) + ((v & ODD_2BIT_MASK) >> 2);
        v = (v & EVEN_4BIT_MASK) + ((v & ODD_4BIT_MASK) >> 4);
        v = (v & EVEN_8BIT_MASK) + ((v & ODD_8BIT_MASK) >> 8);
        return (v & EVEN_16BIT_MASK) + ((v & ODD_16BIT_MASK) >> 16);
    }
};
```

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)