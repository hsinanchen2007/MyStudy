### 解题思路
1. 先判断参数的正负，为负数时 flag 为 1， 负数变为相反数， 为正数时不做操作
2. 定义数组用来存放参数的每位上的数字
3. 当参数大于等于 1 时循环拿取每位上的数字 存放在数组里
4. 遍历数组拿到反转后的数字
5. 判断是否需要加负号，并判断 是否在 范围内(刚开始写的是 if 判断， 后改为 三目运算符 )
### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let flag;
    let newX = 0;
    if (x < 0) {
        flag = 1;
        x = -x;
    }
    let reverseX = [];
    while (x >= 1) {
        reverseX.unshift(x % 10);
        x = Math.floor(x / 10);
    }
    reverseX.forEach((item, i) => {
        newX += item * Math.pow(10, i);
    });
    if (flag == 1) {
        newX = -newX;
        return (newX >= -1 * Math.pow(2, 31))?newX:0;
    } else {
        return (newX <= 1 * Math.pow(2, 31) - 1)?newX:0;
    }
};
```