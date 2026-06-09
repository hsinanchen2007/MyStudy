#### 进位判断
按小学加法思路，申明一个变量用来保存进位的状态，题面的加1可以认为是最低位获得一次进位，逆序之后挨个判断当前元素加上 **低位的进位**之后是否会再次**进位**，并以此调整变量值，最后注意遍历完成之后如果还有一次进位需要做对应处理

```javascript
var plusOne = function (digits) {
    let flag = 1
    for (let i = digits.length - 1; i >= 0; i--) {
        if ((digits[i] + flag) === 10) {
            digits[i] = 0
            flag = 1
        } else {
            digits[i] += flag
            flag = 0
        }
    }
    if (flag === 1) {
        return [1, ...digits]
    }
    return digits
};
```