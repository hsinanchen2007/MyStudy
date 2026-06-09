### 解题思路
每次有效操作只会让总水量的变化有这四种操作
-x
+x
-y
+y
所以我们只要找到整数a,b使得ax+by=z成立
根据贝祖定理，只要x，y的最大公约数是z的倍数，就能找到

求最大公约数使用辗转相除法

### 代码

```javascript
/**
 * @param {number} x
 * @param {number} y
 * @param {number} z
 * @return {boolean}
 */
var canMeasureWater = function(x, y, z) {
    if(x==z||y==z||x+y==z) return true
    if(x+y<z) return false
    //ax+by=z,只要z是x和y的最大公约数的倍数，那么a,b是存在的
    return z%maxCommonDivisor(x,y)==0
};
//使用辗转相除法求最大公约数
var maxCommonDivisor = function(x, y) {
      /*
    x=8,y=6
    如果能整除那么最大公约数就是y，否则将取余的结果给y，将原本的y值给x
    x%y-->2--->x=6,y=2
    x%y-->0--->return y
     */
      let r;
      while ((r = x % y)) {
        x = y;
        y = r;
      }
      return y;
    };
```