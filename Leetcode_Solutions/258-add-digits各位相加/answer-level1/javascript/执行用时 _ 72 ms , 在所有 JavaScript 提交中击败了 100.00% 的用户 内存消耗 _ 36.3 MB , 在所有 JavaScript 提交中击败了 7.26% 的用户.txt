```javascript []
var addDigits = function (num) {
    
    let final = 0
    function Calculation(num) {
        let nums = num.toString().split('')
        if (nums.length == 1) {
            final = num
        } else {
            let reuslt = 0
            nums.forEach(res => {
                reuslt += res * 1
            })
            Calculation(reuslt)
        }
    }
    Calculation(num)
    return final
};

console.log(addDigits(38))

/**
 * 解题思路：
 * 
 *  1. 将数字分解，转换为数组，进行计算，直到加到最后只剩下一个个位数
 */
```
