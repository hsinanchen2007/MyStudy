[点击获取原题链接](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/  )
[点击获取原文链接](https://juejin.im/post/5e490d47e51d452705317df3)

## 题目描述

在一个长度为 $n$ 的数组 ``nums`` 里的所有数字都在 $[0, n-1]$ 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

限制: $2 <= n <= 100000$

### 示例：

输入：``[2, 3, 1, 0, 2, 5, 3]``  
输出：``2`` 或 ``3``   

## 题目剖析

对于这样的题目我们可以使用 ``哈希表`` 来解决，具体的步骤如下：

- 遍历数组 ``nums``， 生成 ``哈希表``，其中数字作为 ``key``，``key`` 对应该数字出现的次数
- 遍历该 ``哈希表``，如果碰到出现次数大于 ``1`` 的情况，直接返回该数字

代码如下：

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    const map = new Map()
    for (const num of nums) {
        const val = map.get(num)
        if (map.has(num)) {
            map.set(num, val + 1)
        } else {
            map.set(num, 1)
        }
    }
    for (const [key, val] of map) {
        if (val > 1) {
            return key
        }
    }
};
```

## 优化

对于上面的代码，其实我们只要一次循环就够了，这里就直接放代码了，应该很容易能看懂：

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    const map = new Map()
    for (const num of nums) {
        const val = map.get(num)
        if (map.has(num)) {
            return num
        }
        map.set(num, 1)
    }
};
```



