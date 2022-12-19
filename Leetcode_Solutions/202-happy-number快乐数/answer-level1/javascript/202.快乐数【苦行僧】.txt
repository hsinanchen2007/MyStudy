## 简要说明

本文会介绍两种实现方法：**循环检测法** 和 **分析打表法**

**双指针法**
快指针fast和慢指针slow，假如在一个循环里，他们迟早会相遇。
相关算法：Floyd算法

**哈希算法**
通过结点记录比对来确定是否陷入循环。

**硬编码算法**
通过数学分析，思考论证找到所有可能的枚举，作为结果的判定池。

> 如有疑问或者不足之处，请指出，万分感激

**关于数字的各个位数相加的写法**

```javascript
let n = 123456789
let sum = 0
while (n) { 
    const value = n % 10
    sum += (value * value)
    n = parseInt(n / 10)
}
```

```javascript
let n = '123456789'
let sum = 0
for (let i of n) { 
    sum += ( i * i )
}
```

```javascript
let n = '123456789'
n.split('').reduce((p, i) => p + i * i, 0)
```

这三种的写法效率上是打差不差的，空间上第三种写法空间损耗最大，个人最喜欢第二种写法

## 读题时间（5min）

对输入的数字求每一位的数字的平方和

对得到的结果重复上述操作

- 若最后可以变成1，输出：**true**
- 若始终不可以变成1，输出：**false**

## 初步思路

1. 什么时候终止循环，确定结果？

> 记录过程结果形成list，新的结果和过去的结果进行比对，如果出现重复则可以结束循环，确定结果

2. 如何取它每一位数字进行平方和？

> 除10求余来取每一位的值

```javascript
let sum = 0
while(n) {
    const value = n % 10
    sum += (value * value)
    n = parseInt(n / 10)
}
```
### 深度思考

64位的number，对应的最大值：1.844674407370955e19
以20位均为9的数字为例，第一次平方求和的结果为1620，
以4位均为9的数字为例，第一次平方求和的结果为324

可以推断出：**在有效范围内的数字经过短短几次运算就可以得到一个两位数**
那么如果事先准备好一个100大小的数字存放这些结果，就可以大大省略循环的时间周期。

## 题解学习

**没有注意的细节**

1. 对于四位即四位以上数字，每次循环都会减少一位。
2. 对于三位数，只会被困在243以下的循环内。
3. （**补充**）官方的方法三 硬编码唯一循环，基于实践得出所有非快乐数最终都会进入这个唯一循环：4→16→37→58→89→145→42→20→4

**难以理解的细节**

1. 弗洛伊德循环查找算法…… 这名字是咋起的…… 逻辑设计的倒是有趣～
2. （**补充**）通过关联性题目找到 弗洛伊德循环查找算法 的 相关“兄弟”：Floyd算法，Floyd 判圈算法，以及我个人觉得可以归类为双指针法

## 代码解析

### 方法一：循环检测法

用一个Set集合来存储过程中产生的值

若在不满足1的情况下，出现Set存在的元素，说明进入了循环，可以结束代码，返回false

**算法：**

```javascript []
/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function(n) {
    // 无缓存破解
    if (n === 1) return true
    const list = new Set()
    while(!list.has(n)) {
        list.add(n)
        let sum = 0
        while(n) {
            const value = n % 10
            sum += (value * value)
            n = parseInt(n / 10)
        }
        if (sum === 1) return true
        n = sum
    }
    return false
}
```

### 方法二：分析打表法

缓存两位数字以内的结果

map存储100以内的结果，当平方和在一百以内时，结局已经注定

用set缓存为ture的结果，当n小于100时，查找set来判断返回结果

**算法：**

```javascript []
/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function(n) {
    const list = new Set([1, 7, 10, 13, 19, 23, 28, 31, 32, 44, 49, 68, 70, 79, 82, 86, 91, 94, 97])
    // 注意边界处理
    while(n >= 100) {
        let sum = 0
        while(n) {
            const value = n % 10
            sum += (value * value)
            n = parseInt(n / 10)
        }
        n = sum
    }
    return list.has(n)
};
```

**执行结果**
![image.png](https://pic.leetcode-cn.com/07545ee1a91daf3cdf3cab62431d96c198ff33cb8bc105c610207044306966c1-image.png)