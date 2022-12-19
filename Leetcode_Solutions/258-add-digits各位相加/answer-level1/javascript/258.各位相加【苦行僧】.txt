## 读题时间（3min）

1. 输入：非负整数
2. 不断计算每一位数字相加的和
3. 输出：最终这个和为一位数时的结果

## 初步思路

本来呢我打算老老实实根据题目的意思，不断循环或者递归去得到最后的结果，但是题目里有“进阶”两个字

这…… 我就不能忍了，估摸这应该有规律——数学归纳法！！！
然后就发现都是以9的倍数递减的！！！

**算法：**

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function(num) {
    if (num < 10) return num
    return num % 9 || 9
};
```

**复杂度分析：**

- 时间复杂度：O(1)
- 空间复杂度：O(1)

**执行结果：**

![image.png](https://pic.leetcode-cn.com/f4a8525d713e0f4b050866916f4a016762bbb71363cad06c46bc03fcfffeef29-image.png)


另外的算法思路：

1. 暴力求解（按照题目规则循环或者递归）

**核心算法：**

各数字之和

```javascript
function addNumber(num) {
    let sum = 0
    for (let item of num ) {
        sum += +item
    }
    return sum
}
```

```javascript
function addNumber(num) {
    return (num + '').split('').reduce((p, i) => p + +i, 0)
}
```

2. 哈希缓存

> 计算观察可以得到在js里最大精度为16位的整数只通过一次循环就小于 16 * 9 这个量级了。
> 因此可以做一个map计算保存 144 内的所有结果，然后只需要一次计算，就可以通过map找到相应的答案

## 深入思考

如何解释找到这个9的规律呢？

满10进1，中间隔个9：1 + 9 = 1 + 0 = 1

可以看出1在前后并没有变化，因此对于大于10的数值可以“消9”处理，也就是结果取余

但当本身只有9的情况下，无法再进行有效的进位消除，因此对于大于10的数值取余为0，则有一个9剩余