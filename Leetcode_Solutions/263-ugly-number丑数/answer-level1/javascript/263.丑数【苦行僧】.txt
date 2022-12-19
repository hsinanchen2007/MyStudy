## 读题时间（2min）

丑数就是只包含质因数 2, 3, 5 的正整数。

输入：不会超过 32 位有符号整数的范围: [−2^31,  2^31 − 1]。

输出：Boolean值

## 初步思考

1. 没啥思路…… 把这个数不断除？
2. 不对可以求余判断，如果有余数，说明不能除了，否则可以继续往下除
3. 以此类推，把2，3，5都过一遍，最后剩下的如果不是1，那就不是丑数
4. 这样有没有可优化的地方？
5. 可以被5除的前提是，个位是0或者5，可以根据个位来优先判断
6. 再根据是否是偶数来判断能否继续被2除
7. 再根据多位相加，判断是否能被3除，若可以，则进行

**注意细节**

1. 这里可能是负整数，需要排除
2. 关于2 可以做位运算诶～

### 这里我做了实验——探究位运算和除法运算的效率

```javascript
function caculateTime(callback) {
  const begin = new Date()
  callback()
  const end = new Date()
  return end.getTime() - begin.getTime()
}

// 位运算
const bitwise = () => {
  let cnt = 1000000
  while (cnt--) {
    const result = cnt >> 1
  }
}
// 除法运算
const division = () => {
  let cnt = 1000000
  while (cnt--) {
    const result = cnt / 2
  }
}

console.log('除法运算的测试：')
let sum2 = 0
for (let i = 0; i < 1000; i++) {
  sum2 += caculateTime(division)
}
console.log(sum2 + 'ms')

console.log('位运算的测试：')
let sum1 = 0
for (let i = 0; i < 1000; i++) {
  sum1 += caculateTime(bitwise)
}
console.log(sum1 + 'ms')
```

在如上情况的测试结果：

![image.png](https://pic.leetcode-cn.com/67624e2d24d5f755181568019b0305861311ce4e5b442ed11e0e99c13734b093-image.png)

我想了一下，先后执行顺序是否会有影响，于是调换了一下顺序，得到的测试结果：

![image.png](https://pic.leetcode-cn.com/f1baeeabbcb0d6cd5bbdcea634f46840194eaa99b35086f62d2dee73077a9b14-image.png)

我又想是不是因为很多运算，并不是2的整除，于是更改了校验的计算

```javascript
// 位运算
const bitwise = () => {
  let cnt = 1000000
  while (cnt--) {
    const result = 10000000000 >> 1
  }
}
// 除法运算
const division = () => {
  let cnt = 1000000
  while (cnt--) {
    const result = 10000000000 / 2
  }
}
```

测试结果：

![image.png](https://pic.leetcode-cn.com/66a6ba0b4379fa69a905cdcbd7dcb7c3c209dbbb62c4a2c241fb5b60a5204239-image.png)

![image.png](https://pic.leetcode-cn.com/860b290bd431833a673122b29d347d14ca71e45831fd0ba3794d29074b931c86-image.png)

![image.png](https://pic.leetcode-cn.com/8ef79c688dd11c4e06398cb1fa7d659d1313dc21e1e1520bd373fcc8b34a369e-image.png)

so…… 我只能说JavaScript里的除法呀，被优化的忒好了

## 题解学习

**没注意到的细节**

1. 对于可能只有2的因数的丑数，通过if elseif 节省判断其他因数的时间
 
（这让我思考觉得，任何一个算法，根据实际数据还可以进一步做微调节省时间）

拿这道题举例，如果实际测试数据里面，因子2，3，5的占比为3:2:1，那么可以把if elseif判断顺序设置为 先判断2，再判断3，再判断5；若占比为1:2:3，那么先后顺序就改为5，3，2

## 代码解析

### 方法一：求余探底法

> 一定程度减少num被除的次数

**算法：**

```javascript
/**
 * @param {number} num
 * @return {boolean}
 */
var isUgly = function(num) {
    // 排除负数
    if (num < 1) return false
    // 为除数减少乘法运算
    const divisorMap = [1,2,3,6,5,10,15,30]
    while(num > 1) {
        let pos = 0
        if (num % 2 === 0) {
            pos++
        }
        if (num % 5 === 0) {
            pos = pos + 4
        }
        if (num % 3 === 0) {
            pos = pos + 2
        }
        if (pos > 0) {
            num = num / divisorMap[pos]
        } else {
            return false
        }
    }
    return true
};
```

**复杂度分析：**

时间复杂度：O(logn)
空间复杂度：O(1)

**执行结果：**

![image.png](https://pic.leetcode-cn.com/0e982719ef3928d6af3ae2696448745a98e4444905f99b54853290f78f599b76-image.png)


> 最大程度减少被除的次数

**算法：**

```javascript
/**
 * @param {number} num
 * @return {boolean}
 */
var isUgly = function(num) {
    // 排除负数
    if (num < 1) return false
    let divisor2 = 2
    while(num % divisor2 === 0) {
        divisor2 = divisor2 << 1
    }
    divisor2 = divisor2 >> 1
    let divisor3 = 3
    while(num % divisor3 === 0) {
        divisor3 = divisor3 * 3
    }
    divisor3 = divisor3 / 3
    let divisor5 = 5
    while(num % divisor5 === 0) {
        divisor5 = divisor5 * 5
    }
    divisor5 = divisor5 / 5
    num = num / divisor2 / divisor3 / divisor5
    if (num === 1) return true
    else return false
};
```

**复杂度分析：**

时间复杂度：O(logn)
空间复杂度：O(1)

**执行结果：**

![image.png](https://pic.leetcode-cn.com/e448b1573a336262b483d66d4c78ba025353dd41a91eb53e09efea636fae9579-image.png)


> 意识到重复判断影响效率之后改进写法

**算法：**

```javascript
/**
 * @param {number} num
 * @return {boolean}
 */
var isUgly = function(num) {
    // 排除负数
    if (num < 1) return false
    while(num > 1) {
        if (num % 2 === 0) {
            num = num / 2
            continue
        }
        if (num % 3 === 0) {
            num = num / 3
            continue
        }
        if (num % 5 === 0) {
            num = num / 5
            continue
        }
        return false
    }
    return true
};
```

**复杂度分析：**

时间复杂度：O(logn)
空间复杂度：O(1)

**执行结果：**

![image.png](https://pic.leetcode-cn.com/f01601be2b79f7c548c4b664ea6f35149c5a54a0cae7459b1a1896dc97241cf4-image.png)


> 学习更优美的写法

**算法：**

```javascript
/**
 * @param {number} num
 * @return {boolean}
 */
var isUgly = function(num) {
    // 排除负数
    if (num < 1) return false
    ;[2, 3, 5].map(item => {
        while (num % item === 0) num = num / item
    })
    return num === 1
};
```

**复杂度分析：**

时间复杂度：O(logn)
空间复杂度：O(1)

**执行结果：**

![image.png](https://pic.leetcode-cn.com/f6d5955cf6b73b38aaa9d936125f06f5faf60559184f53b9201dba9c5c41d9b2-image.png)
