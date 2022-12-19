### 解题思路
/**
1. 找状态 
```
        最优策略中最后一个完全平方数为 i
        凑够 n  最少需要 f(n)
```
2. 转移方程
```
        f(n) = min (f(n-1),f(n-4),f(n-9),f(n-16),....)   1 <= i <= Math.floor(sqrt(n))
```
3. 初始状态
```
        f(0) = 0
        f(1) = 1
        f(2) = 2;
        f(3) = 3;
        sqrt(n) % 1 == 0 -->> min = 1
```
 4.顺序 从小到大
 */

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var numSquares = function(n) {
    let arr = [];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    if(n!==0 && Math.sqrt(n) % 1 == 0){
        return 1;
    }
    let top;
    for(let i = 4; i<=n; i++){
        let min = Number.MAX_VALUE;
        let sqrt = Math.sqrt(i);
        if(sqrt % 1 == 0){
                arr[i] = 1;
                continue;
        }
        top = Math.floor(sqrt)
        for(j = 1; j<= top ; j++){
            let double = j * j;
            min = Math.min(min, arr[i-double])
        }
        arr[i] = min + 1;
    }
    return arr[n];
};






```