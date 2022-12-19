思路：
1>如果两个字符串长度不相同，则在较短的字符串前补0；
2>从尾部开始循环，依次相加；如果相加的结果>9则进位
3>检测进位是否为0；如不为0；则加到最前方

```
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function (num1, num2) {
    let extra = 0;
    while(num1.length > num2.length){
        num2 ='0' + num2
    }
    while (num1.length < num2.length){
        num1 = '0' + num1
    }
    let target = [];
    let i = num1.length-1;
    while(i>=0){
        let sum = Number(num1[i]) + Number(num2[i]) + extra
        if (sum > 9) {
            sum = sum % 10;
            extra = 1;
        } else {
            extra = 0;
        }
        target.unshift(sum)
        i--
    }
    if(extra>0){
        target.unshift(extra)
    }
    return target.join('')
};
```
