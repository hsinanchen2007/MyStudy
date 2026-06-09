### 解题思路
找到第一个6，将其改为9

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var maximum69Number  = function(num) {
    const arr = String(num).split('')
    const index = arr.indexOf('6')
    if(index > -1) {
        arr[index] = 9
        return Number(arr.join(''))
    }
    return num
};
```