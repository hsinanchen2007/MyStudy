### 解题思路
裴蜀定理: 对于任意整数x, y，一定存在整数a，b，使得ax+by一定是Gcd(x,y)的倍数。
所以本题转化为求z是是否是x，y的最大公约数的倍数

因此这道题可以完全转化为裴蜀定理。还是以题目给的例子x = 3, y = 5, z = 4，我们其实可以表示成3 * 3 - 1 * 5 = 4, 即3 * x - 1 * y = z。我们用a和b分别表示3
升的水壶和5升的水壶。那么我们可以：

倒满a（1）
将a倒到b
再次倒满a（2）
再次将a倒到b（a这个时候还剩下1升）
倒空b（-1）
将剩下的1升倒到b
将a倒满（3）
将a倒到b
b此时正好是4升
上面的过程就是3 * x - 1 * y = z的具体过程解释。

也就是说我们只需要求出x和y的最大公约数d，并判断z是否是d的整数倍即可。


### 代码

```javascript
/**
 * @param {number} x
 * @param {number} y
 * @param {number} z
 * @return {boolean}
 */
var canMeasureWater = function(x, y, z) {
    if (x+y <z) return false;
    if(z ===0) return true;
    if(x === 0) return y === z;
    if(y === 0) return x === z;
    const Gcd = (a,b) =>{
        let min = a < b ? a : b;
        while(min) {
            if(a%min === 0 && b %min ===0){
                return min;
            }else{
                min--
            }
        }
        return 1;
    }
    return z % Gcd(x,y) === 0;
};
```