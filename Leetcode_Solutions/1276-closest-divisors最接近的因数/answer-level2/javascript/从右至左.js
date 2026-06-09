### 解题思路
错误示范
# 方式1
求num质因数乘积=>集合
从低到高找出两数乘积均等规律
```
    var k1 = k2 = 1
    var len = Math.floor(r.length / 2)
    for (let i = 0; i < len; i++) {//找出两个最小的相乘，递归
        k1 = k1 * r[i];
        k2 = k2 * r[i + Math.ceil(r.length / 2)];//Math.round四舍五入
    }
      
```
# 方式2
从小去除，记录前面相乘积，若大于被除完的数，就是两数乘积相差最小的
```
    for (let i = 2; i <= num; i++) {
        while (num % i == 0) {
            k = k * i
            num = num / i
            if (isSushu(i, num)) {//是素数
                if (k > num) {//前面乘积不一定比最后一者小，1001=7*11*13
                    return [num, k]
                } else {
                    return [k, num]
                }
            } else {
                if (k >= num) {
                    return [num, k]
                }
            }
        }
    }
```

改进点，除完后循环边界值应当缩小

### 代码

```javascript
/**
 * @param {number} num
 * @return {number[]}
 */
var closestDivisors = function (num) {
    for (let i = parseInt(Math.sqrt(num + 2)); i >= 1; i--) {//开根号一定要num+2,是否可缩小有点像数学性质

        if ((num + 1) % i == 0) {
            var k = (num + 1) / i
            return [i, k]
        }
        if ((num + 2) % i == 0) {
            var k = (num + 2) / i
            return [i, k]
        }
    }

};
```

# 参考数学题型
两数a,b最大公约数、最小公倍数