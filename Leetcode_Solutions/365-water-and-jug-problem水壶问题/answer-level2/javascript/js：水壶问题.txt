### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} x
 * @param {number} y
 * @param {number} z
 * @return {boolean}
 */
var canMeasureWater = function(x, y, z) {
    if( x + y < z){
        return false;
    }else{
        if(x === 0 && y ===0){
            return z === 0;
        }else{
            return z % gcd(x, y) === 0;
        }
    }
    function gcd(x, y){
        if(y === 0){return x;}
        else{
            x %= y;
        }
        return gcd(y, x);
    }
};
```