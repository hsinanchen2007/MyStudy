### 解题思路
for 循环
数字转为字符串 => 通过for 循环从大到小依次拿取值放入新的变量里 => 添加正负 => 是否整数溢出 => 返回值
### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let stringX = Math.abs(x).toString();
    let result = '';
    for(let i = stringX.length-1; i >= 0; i--){
        result += stringX[i];
    }
    result *= Math.sign(x);
    if( result > Math.pow(2, 31) - 1 || result < Math.pow(-2, 31)){
        return 0;
    }
    return result;
};
```
### 解题思路
reverse 反转数组。
数字 => 字符串 => 数组 => 反转数组 => 添加正负 => 是否整数溢出 => 返回值
```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    const result = Math.abs(x).toString().split('').reverse().join('') * Math.sign(x)
    if(result > (Math.pow(2,31)-1) || result < Math.pow(-2,31)){
        return 0;
    }
    return result;
};
```