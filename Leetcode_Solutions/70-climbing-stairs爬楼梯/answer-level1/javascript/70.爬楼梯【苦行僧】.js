## 读题时间(3min)

1. n是一个正整数
2. n并没有做大小限制（可能需要做很多边界值的考虑）
3. 需要计算由1，2组成n的排列组合

## 初步探索

> 在测试用例里尝试用例：999999999999999，预期结果是1

说明这道题目并不考虑n取值过大的情况，即只需要考虑算法本身即可（符合它的难度为简单）

> 尝试计算了一下4，5，6的情况

输入 1: 输出 1
输入 2: 输出 2
输入 3: 输出 3
输入 4: 输出 5
输入 5: 输出 8
......
目前相当满足斐波那契数列！！！ 小激动

查一查它的对应公式：

![image.png](https://pic.leetcode-cn.com/dc12a62dd062b1c4a1451ba79cdbbb10530168df237c3055ea6a0d38cd8f3555-image.png)

忍不住尝试一波～

**算法：**

```javascript
/**
 * @param {number} n
 * @return {number}
 */
// 公用常量
const sqrt5 = Math.sqrt(5);
var climbStairs = function(n) {
    // 斐波那契数列
    return (Math.pow((1 + sqrt5) / 2, n + 1) - Math.pow((1 - sqrt5) / 2, n + 1))/sqrt5
};
```

**复杂度分析：**

- 时间复杂度：O(log(n))，这里需要考虑Math.pow方法的影响
- 空间复杂度：O(1)

**执行结果：**

![image.png](https://pic.leetcode-cn.com/e852a8488d0c3faad53c94a2cfd1b7496268cc6500ce3d75864237fc59166a12-image.png)

## 深入探索

> 还有什么其他的解法？

直接还原递推的过程

**算法：**

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    if (n < 4) return n
    let prevOne = 2
    let prevTwo = 3
    let result = 0
    for(let i = 4; i <= n ; i++) {
        result  = prevOne + prevTwo
        prevOne = prevTwo
        prevTwo = result
    }
    return result
};
```

**复杂度分析：**

- 时间复杂度：O(n)
- 空间复杂度：O(1)

**执行结果：**

> 可以看出，耗时并不是稳定的
> 从代码简约上来看，上一种算法更佳，但实际执行效率却会根据测试数据来看，这里的时间复杂度并不是说O(log(n))就一定比O(n)的代码执行时间更短

![image.png](https://pic.leetcode-cn.com/f53412159ab203410dc2e2aae9b8c2d74befd67a4c1334225f7b21e3695c586a-image.png)
![image.png](https://pic.leetcode-cn.com/3384cdde7bad4a82791b683e4515966a15ba29f88824eb9dde0e56f75fbc8d30-image.png)

还有什么方法呢？阅读其他人的题解中……

看了一下官方的题解，第一种暴力法时间复杂度O(n^2)……可以看到执行了非常非常多重复的代码，我这就不推荐了……

记忆化递归其实就和我上面这种直接还原递推过程的算法一样，区别在于它存储了过程值，使得在重复执行多个测试用例时节省了时间

今天就先写到这里，未完待续……




