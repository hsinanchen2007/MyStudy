1. 首先这道题的题干可以分解为 **x^2 + y^2 = r^2** (c = r^2, 因此缩小循环范围至[0,r])
2. 这个方程明显是一个圆的方程，因为x>=0,y>=0 所以循环范围为第一象限的**四分之一圆弧**
3. 由图可知（没有画图，自行脑补吧），该圆弧由**y = x**这个方程分为上下对称的两部分，因此，若上半部分存在整数解，下半部分定然存在，反之
4. 最后循环范围可以缩小到**八分之一圆弧**，即**[0, 0.5^-1]**这个区间
5. 剩下的就是遍历这八分之一圆弧上面是否有整数解析，代码如下

```javascript
var judgeSquareSum = function(c) {
    const flag = Math.sqrt(0.5) * Math.sqrt(c)
    for(let a = 0;a <= flag; a++){
        const b = Math.sqrt(c - a*a)
        if(parseInt(b) === b){
            return true
        }
    }
    return false
};
```