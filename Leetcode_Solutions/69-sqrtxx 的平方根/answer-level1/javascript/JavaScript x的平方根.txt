解一：
> 现成的`sqrt`函数来一个。

```js
var mySqrt = function(x) {
    return parseInt(Math.sqrt(x));
};
```
![](https://pic.leetcode-cn.com/65078343d8ff6def7ac39383a04bd4486c8b16d4a4f899bde5579cba2a59c0d5-file_1565631569366)

解二：
> 最耿直的自增暴力解。

```js
var mySqrt = function(x) {
    var re = 0;
    while(!(re*re<=x&&(re+1)*(re+1)>x)){
        re++;
    }
    return re
};
```
![](https://pic.leetcode-cn.com/f0cef0aa1f90cb96dcb82b1f5e99ec96da73972d9b428be323129ac43927d427-file_1565631569370)

解三：
> 牛顿法，只用知道迭代公式就好了（原理在数学规划课上学得差不多了）：$re_{n+1}=re_{n}-\frac{f(re_n)}{f'(re_n)}$，在本题中：$f(re_n)=re^2-x$、$f'{re_n}=2\times re$

```js
var mySqrt = function(x) {
    if (x===0) return 0;
    var re = 1;
    while(!(re*re<=x&&(re+1)*(re+1)>x)){
        re = parseInt(re-(re*re-x)/(2*re))
    }
    return re
};
```
![](https://pic.leetcode-cn.com/7cc46378983513068c37d03d2e141a4825bef328ed31f9015672d78150f0f6c1-file_1565631569372)