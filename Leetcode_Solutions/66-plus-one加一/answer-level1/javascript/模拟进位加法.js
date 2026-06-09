### 解题思路
反转数组，使用一个标识保存当前位的加法是否有进位,。加1最高的结果为10，为10则有进位，当前元素变为0，下一个元素要执行加1；不为10则不进位，保留当前结果。结束遍历之后，还要判断是否有进位，有则最后再推1。最后反转数组得到结果。

### 代码

```javascript
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    let reverDigits = digits.reverse()
    let arr = []
    let addFlag = true    
    for (let i = 0, len = reverDigits.length; i < len; i++) {
        if (addFlag) {
            let temp = reverDigits[i] + 1
            if (temp === 10) {
                arr.push(0)
                addFlag = true
            } else {
                arr.push(temp)
                addFlag = false
            }
        } else {
            arr.push(reverDigits[i])
        }
    }

    if (addFlag) {
        arr.push(1)
    }

    return arr.reverse()
};
```