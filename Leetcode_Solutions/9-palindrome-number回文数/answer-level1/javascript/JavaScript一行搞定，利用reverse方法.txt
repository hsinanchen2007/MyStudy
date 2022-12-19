### 解题思路
先把输入值转为字串，字串转为数组，反转，然后比较

为什么转为数组？

因为字符串没法通过array原型上的reverse进行反转

具体是因为string 和array不同，string每次都是一个新的值，array是原来的。（栈地址和堆地址）

所以只能通过方法转换

### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
   return (x+'').split('').reverse().join('') === (x+'')
};
```