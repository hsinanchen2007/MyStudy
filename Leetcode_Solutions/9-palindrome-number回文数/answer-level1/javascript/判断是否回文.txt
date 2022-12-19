### 解题思路
此处撰写解题思路
number.toString() -- 转字符串
判断  length % 2 是否能除尽；按照个数给定不同的 substring(from, to) 脚标
length % 2 为 true; 例如 [1,2,3];脚标对应  012
xMid = Math.floor(length/2)
xLeft = xStr.substring(0, xMid);
xRight = xStr.substring(xMid+1);

length % 2 为 false ；就能被整除，留 0 ；[1,2,3,4];0123
xLeft = xStr.substring(0, length/2);
xRight = xStr.substring(length/2)

array.reverse()  反转
xRight = xRight.split('').reverse().join('')
### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
if(x<0){
    return false;
} else if(x>= 0 && x<10){
    return true;
} else if(x>9) {
    var xStr = x.toString();
    var xLen = xStr.length;
    var xLeft = "";
    var xRight = "";
    if(xLen % 2 === 0){
        xLeft = xStr.substring(0, xLen/2);
        xRight = xStr.substring(xLen/2, xLen);
    } else {
        var xMid = Math.floor(xLen /2);
        xLeft = xStr.substring(0, xMid);
        xRight = xStr.substring(xMid +1, xLen);        
    }
    xRight = xRight.split('').reverse().join('');
    if(xLeft === xRight){
        return true;
    } else {
        return false;
    }
}
};
```