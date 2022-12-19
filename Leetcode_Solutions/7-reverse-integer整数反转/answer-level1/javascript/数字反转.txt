### 解题思路
此处撰写解题思路
取出正负数标识，获取数值的绝对值，字符串转数组，反转；

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    const sign = x.toString().includes('-') ? -1 : 1
    let y = x>0?x:(x+'').split('-')[1]
    let tar = Number((y+'').split('').reverse().join('')) || 0
    const num = sign*tar
    if(num<Math.pow(-2,31)||num>(Math.pow(2,31)-1)){
        return 0
    }
    return num
};
```