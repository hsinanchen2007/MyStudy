### 解题思路
我使用正则表达式来解决这个问题，根据题目的描述，我们可以知道，首先要跳过空格字符串，直到查询到非空格字符，首字符可以是正负号或者是数字，并且取其后母尽可能多的连续数字，直到查询到非数字字符，并且最后的结果数值应在[−2^31,  2^31 − 1]的范围内，若超过则返回极限值。若首字符不是一个有效整数字符则返回0。所以检测第一个有效整数字符的正则表达式应该是：/^[\s]*[-+]{0,1}[0-9]+/。这个表达式以0到若干个空白字符，0到1个-+符号，1个以上的数值，并且该匹配的字符应是在开头。

### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
  let reg = /^[\s]*[-+]{0,1}[0-9]+/
  if(reg.test(str)){
    let num = Number(str.match(reg)[0])
    if(num > Math.pow(2,31)-1){
      return Math.pow(2,31)-1
    }else if(num < -Math.pow(2,31)){
      return -Math.pow(2,31)
    }else{
      return num
    }
  }else{
    return 0
  }
}
```