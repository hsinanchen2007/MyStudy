## 读题时间（5min）

找出第 n 个丑数

丑数是只包含质因数 2，3，5的正整数

1 是丑数

n <= 1690

## 思辨之旅【原初步思路】

> 考虑到思维的连贯性，改成连续记述方式

1. 这道题马上让我想到斐波纳切数列……
2. 之后每一个丑数都是已知丑数乘以2或3或5

然后我迅速尝试了一种写法

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var nthUglyNumber = function(n) {
    const initList = [1,2,3,4,5,6]
    if (n <= 6) return initList[n-1]
    const uglyNumberSet = new Set(initList)
    let cnt = 6
    let number = 7
    let result = 0
    while(n !== cnt) {
        number++
        if (number % 2 === 0) {
            result = number / 2
            if (uglyNumberSet.has(result)) {
                cnt ++
                uglyNumberSet.add(result)
            }
            continue
        }
        if (number % 3 === 0) {
            result = number / 3
            if (uglyNumberSet.has(result)) {
                cnt ++
                uglyNumberSet.add(result)
            }
            continue
        }
        if (number % 5 === 0) {
            result = number / 5
            if (uglyNumberSet.has(result)) {
                cnt ++
                uglyNumberSet.add(result)
            }
            continue
        }
    }
    return number
};
```

当输入的值是1690时，完美超时……

![image.png](https://pic.leetcode-cn.com/a1b165ebff1ea2ee632cd09a926e00ac6887c540b0093d98304bf8f614e2adfb-image.png)

注意，这里有一个利用复杂度分析的小技巧：

当前代码的时间复杂度是O(n), 这意味着新设计的时间复杂度要小于O(n)

在扫了一眼官方的动态规划之后……

耗时：104ms

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var cacheArray = (function () {
    // 尝试预存
    const maxNth = 1690
    let p2 = p3 = p5 = 0
    const cacheArray = new Array(maxNth)
    cacheArray[0] = 1
    for (let i = 1; i < maxNth; i++) {
        const nextP2 = cacheArray[p2] * 2
        const nextP3 = cacheArray[p3] * 3
        const nextP5 = cacheArray[p5] * 5
        const realNext = Math.min(nextP2, nextP3, nextP5)
        if (realNext === nextP2) p2++
        else if (realNext === nextP3) p3++
        else p5++
        // 需要去重
        if ( cacheArray[i - 1] !== realNext ) {
            cacheArray[i] = realNext
        } else {
            i--
        }
    }
    return cacheArray
})()
var nthUglyNumber = function(n) {
    return cacheArray[n - 1]
};
```

时间复杂度大大减少，但是减少到什么程度，还真说不上来，个人觉得是O(nlogn)的时间复杂度

然后我又去看来一下官方题解，发现它并没有做去重的处理，那么官方的去重是怎么做的呢？

原来是考虑到可能 nextP2，nextP3，nextP5 有相同的情况，此时一次循环会有多枚指针移动。

最终结果

### 方法一： 动态规划

耗时：76ms

**算法：**

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var cacheArray = (function () {
    // 尝试预存
    const maxNth = 1690
    let p2 = p3 = p5 = 0
    const cacheArray = new Array(maxNth)
    cacheArray[0] = 1
    for (let i = 1; i < maxNth; i++) {
        const nextP2 = cacheArray[p2] * 2
        const nextP3 = cacheArray[p3] * 3
        const nextP5 = cacheArray[p5] * 5
        const realNext = Math.min(nextP2, nextP3, nextP5)
        // 考虑到nextP2, nextP3, nextP5，可能有相同的，因此这里的指针可能一次移动多次
        if (realNext === nextP2) p2++
        if (realNext === nextP3) p3++
        if (realNext === nextP5) p5++
        cacheArray[i] = realNext
    }
    return cacheArray
})()
var nthUglyNumber = function(n) {
    return cacheArray[n - 1]
};
```

**复杂度分析：**

时间复杂度：O(nlogn)
空间复杂度：O(n)

**执行结果：**

![image.png](https://pic.leetcode-cn.com/d6b3289b0d43aba1a6caa680991cc44853b74bebd4990b697d4258a04b313b26-image.png)

表示白天还是76ms的……

### 方法二： 优先序列


**算法：**

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var cacheArray = (function () {
    const maxNth = 1690
    const cacheArray = new Set()
    const sortList = [1]
    while(cacheArray.size < maxNth) {
        const item = sortList.shift()
        if (cacheArray.has(item)) continue
        cacheArray.add(item)
        sortList.push(item * 2)
        sortList.push(item * 3)
        sortList.push(item * 5)
        sortList.sort((a, b) => {
            return a - b
        })
    }
    return Array.from(cacheArray)
})()
var nthUglyNumber = function(n) {
    return cacheArray[n - 1]
};
```

**复杂度分析：**

时间复杂度：O(nlogn)
空间复杂度：O(n)

**执行结果：**

![image.png](https://pic.leetcode-cn.com/093f751314ad816de5a33673726cf4b7d5c6e9d962670ae6d5279ef704588d8c-image.png)
