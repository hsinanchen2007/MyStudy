*法一：双指针*

```js
var maxDistToClosest = function(seats) {

    let left = seats.indexOf(1);
    let right = seats.indexOf(1, left);
    let arr = [left];
    let len = seats.length;

    for (let i = 0; i < len; i++) {
        if (seats[i] === 1) {
            left = i;
            right = seats.indexOf(1, left+1); 
            if (right !== -1) {
                arr.push(Math.floor((right-left) / 2))
            } else {
                arr.push(len-left-1)
            }
        } 
    }

    return Math.max(...arr)
};
```

*法二*

处理这三种情况就可以

•	座位为001时
•	座位为101时
•	座位为100时

```js
var maxDistToClosest = function(seats) {

    let arr = seats.join('').split('1').map((item) => item.length);
    let leftMax = arr.shift();
    let rightMax = arr.pop();
    let zeroMax = Math.max(...arr);
    let centerMax = Math.ceil(zeroMax / 2)

    return Math.max(leftMax, rightMax, centerMax)
};
```

