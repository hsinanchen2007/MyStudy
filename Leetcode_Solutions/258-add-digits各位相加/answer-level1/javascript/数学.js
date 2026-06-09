### 解题思路
假设一个三位数整数n=100*a+10*b+c,变化后addn=a+b+c；
两者的差值n-addn=99a+9b，差值可以被9整除，说明每次缩小9的倍数
那么我们可以对res=num%9，若不为0则返回res，为0则返回9
### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function(num) {
    if(num>9){
        num = num%9;
        if(num==0){
            return 9;
        }
    }
    return num;
};

```