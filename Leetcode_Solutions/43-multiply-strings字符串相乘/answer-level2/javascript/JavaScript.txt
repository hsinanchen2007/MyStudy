### 解题思路
垃圾代码, 模拟竖式相乘
为此需要构造两个计算单元
    1. 单个数字与另一个数字相乘
    2. 两个带偏移的竖式相加合并
最后, 只需要取其中一个数字按位乘与另一个数, 并将结果以竖式相加合并即可

为了计算简便, 多处将数组采用反转形式计算

### 代码

```javascript
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */

// 数字转数组
function numToArr(num) {
    return Array.from(String(num))
}
function numToArrReverse(num) {
    return numToArr(num).reverse()
}

// 竖式相加
// 动作: 将 reversedBasedTrimArr 和 targetTrimArr 以 reversedBasedTrimOffset 的偏移量相加
// 结果: 竖式相加的结果数组 (反转)
function mergeVerticalTrim(reversedBasedTrimArr, reversedBasedTrimOffset, targetTrimArr) {
    let adv = 0 // 进位
    let offset = reversedBasedTrimOffset // 移位
    // 当目标竖式仍有剩余项或进位有值时循环
    while(targetTrimArr.length>0 || adv!==0) {
        // 求值
        const digit = Number(targetTrimArr.pop() || 0)
        const res = reversedBasedTrimArr[offset] + digit + adv
        // 赋个位值
        reversedBasedTrimArr[offset] = res%10
        // 进位
        adv = res>=10 ? 1 : 0
        // 移位
        offset++
    }
    return reversedBasedTrimArr
}

// 数相乘
// 动作: 将 reversedBasedTrimArr 与 targeBitDigit 相乘
// 返回: 乘积的数组 (反转)
function multiplyTrim(reversedBasedTrimArr, targeBitDigit, resultLength) {
    const resArr = Array(resultLength).fill(0)
    // 遍历大数, 将数位与大数每一位相乘, 并合并竖式
    reversedBasedTrimArr.forEach((item, index) => {
        const res = item * targeBitDigit
        mergeVerticalTrim(resArr, index, numToArr(res))
    })
    return resArr
}

// 数反转
// 动作: 将 reversedTargetTrim 末尾的 0 去除并反转
// 返回: 正置数组
function reverseValidTrim(reversedTargetTrim) {
    // 清除末尾 0
    while(reversedTargetTrim[reversedTargetTrim.length-1] === 0) reversedTargetTrim.pop()
    // 反转
    return reversedTargetTrim.reverse()
}

var multiply = function(num1, num2) {
    // Guards
    if ([num1, num2].includes("0")) return "0"
    // Processing
    // 结果集, 长度必定不会大于两长度之和
    const resLength = num1.length + num2.length
    const resArr = Array(resLength).fill(0)
    // 转换为数组, 并反转
    const num1ArrReverse = numToArrReverse(num1)
    const num2ArrReverse = numToArrReverse(num2)
    num2ArrReverse.forEach((digit, index) => {
        // 计算当前位的乘积
        const currentBitResArrReverse = multiplyTrim(num1ArrReverse, Number(digit), resLength)
        const currentBitResArr = reverseValidTrim(currentBitResArrReverse)
        // 乘积以竖式形式合并到结果集中
        const currentMergedResArrReverse = mergeVerticalTrim(resArr, index, currentBitResArr)
    })
    // 组装结果
    return reverseValidTrim(resArr).join("")
};
```