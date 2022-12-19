### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function (x) {
    //将数取绝对值，然后转换成字符串，然后转换成数组
    let numArr = Math.abs(x).toString().split("");
    //将数组反转，再变成字符串
    let newStr = numArr.reverse().join("");
    //判断字符串开头是否为0，若为0则去除
    newStr = newStr[0] === 0? newStr.substring(1,):newStr;
    //判断数字是否为负数，若是则在字符串头部加个"-"
    newStr = x<0?("-"+newStr):newStr;
    //将字符串转为数字
    let newNum = parseInt(newStr);
    //判断数字是否溢出
    if(newNum<-Math.pow(2,31) || newNum>Math.pow(2,31)-1){
        return 0;
    }else{
        return newNum;
    }
};
```