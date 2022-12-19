### 解题思路
1. 使用 & 来判断奇偶数

### 代码

```javascript
/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    //如果指数是0
    if(n === 0){
        return 1;
    }
    //如果指数是1 返回x
    if(n === 1){
        return x;
    }

    //n绝对值，不能为负
    let absn =Math.abs(n);
    //结果不能为0
    let result = 1;
    //不能为0
    while(absn){
        //判断奇偶数
        //absn 也就是 n值，根据最右位是否为1来判断
        //3的二进： 11
        //1的二进： 01
        //是成立的
        if(absn & 1){
            //将当前x累乘到result
            result = result * x;
        }
        
        x = x*x;
        //缩小范围
        absn = Math.floor(absn/2); 

    }

        //是否是负指数
    const isNegative = n < 0;

    return isNegative ? 1 / result : result
};
```