重拾下小学时学的乘法运算，两个数字的乘积，相当于 num1 乘 num2 的每一位的和，因此乘法运算可转化为遍历加法

需要注意的是，js中数字的安全范围在(-2^53 + 1, 2^53 - 1)，超出此范围数字的精度会出错，题目里说明数字的长度小于110，两数相乘是有可能超出安全范围的，又不能使用BigInt 大数类型（不受安全范围限制），所以可转化为字符串避开此限制



```
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var multiply = function(num1, num2) {
    let str = []
    if (num1 === '0' || num2 === '0') return '0'
    for(let i = num2.length - 1; i >= 0; i--) {
        let add = 0
        let firstArr = []
        for(let j = num1.length - 1; j >= 0; j--) {
            const a = Number(num2[i])
            const b = Number(num1[j])
            const multi = a*b + add
            firstArr.unshift(multi%10)
            add = Math.floor(multi/10)
        }
        
        if (add > 0) firstArr.unshift(add)
        let plusNum = firstArr.join('')
        let reverseIdx = num2.length - 1 - i
        let countZero = new Array(reverseIdx).fill(0).join('')
        plusNum = plusNum + countZero
        str.push(plusNum)
    }
    
    while(str.length > 1) {
        const firstNum = str.shift()
        const secondNum = str.shift()
        let add = 0
        let plusArr = []
        for(let i = secondNum.length - 1, j = firstNum.length - 1; i >=0 || j >= 0; i--, j--) {
            const a = Number(secondNum[i]) || 0
            const b = Number(firstNum[j]) || 0
            const sum = a + b + add
            plusArr.unshift(sum%10)
            add = sum >= 10 ? 1 : 0
        }
        if (add > 0) plusArr.unshift(1)
        str.push(plusArr.join(''))
    }
    return str[0] + ''
};
```
![image.png](https://pic.leetcode-cn.com/725fdeb1e9294f1c6f79ec88e25a45b05213696e7d3cb8629ce0cffe8ac9dd55-image.png)
