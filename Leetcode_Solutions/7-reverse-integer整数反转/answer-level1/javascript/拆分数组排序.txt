### 解题思路
1.非负化
2.拆分成数组倒序
3.判断首位0的情况对倒序后的数组做处理
4.判断值范围是否符合
5.按初始值正负性返回值

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    const num = Math.abs(x)
    const rev_num = num.toString().split('').reverse()
    if (rev_num.includes('0') && rev_num[0] === '0') {
        rev_num.shift()
    }
    const fmtNum = rev_num.join('') * (x < 0 ? -1 : 1)
    return (fmtNum < Math.pow(-2, 31) || fmtNum > Math.pow(2, 31) - 1) ? 0 : fmtNum
};
```