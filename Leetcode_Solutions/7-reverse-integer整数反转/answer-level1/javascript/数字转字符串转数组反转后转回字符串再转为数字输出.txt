### 解题思路
此处撰写解题思路
原始数字大于-1（0也在其中）则正常反转，因为前面无符号，反之最后记得补负号
数字转字符串转数组，reverse反转后转回字符串
最后进行判断是否溢出
### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let str,num;
    if(x>-1){
    str=x.toString().split("").reverse().join("");
    num=Number(str);
    }else{
    str=Math.abs(x).toString().split("").reverse().join("");
    num=Number('-'+str);
    }
    if(num>Math.pow(2,31)-1||num<Math.pow(-2,31))return 0;
    return num
};
```