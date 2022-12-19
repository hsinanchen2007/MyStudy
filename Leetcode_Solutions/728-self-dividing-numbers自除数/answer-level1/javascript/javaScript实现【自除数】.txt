```javascript []
var selfDividingNumbers = function (left, right) {
    let arr = []
    
    for(let i = left; i <= right; i++) {
        if (i < 10) {
            arr.push(i)
        } else if(i > 10){
            let n = i.toString()
            let flag = true
            for (let j = 0; j < n.length; j++) {
                if (i % n[j] != 0) {
                    flag = false
                }
            }
            if (flag) {
                arr.push(i)
            }
        }
    }
    return [...arr]
};


console.log(selfDividingNumbers(1, 22))

/**
 * 解题思路：
 * 
 * 1. 根据题意【题中给定上边界和下边界数字，计算这两边界中（含边界）的自然数（自除数 是指可以被它包含的每一位数除尽的数。）】
 * 2. 因此可以想象出，小于10的都是自然数，我们只需要i计算出大于10的自然数
 * 3. 将大于10（自除数不允许包含 0 ）转换成字符串，遍历，如果有一项被除不尽，则舍弃，否则添加到数组中
 */
```
