### 解题思路
考虑出动态转移方程以后，就相信那个公式，不要倒推
难点是找出状态定义，就是定义最顶层楼是F(N) 然后 F(N) = F(N-1) + F(N-2)

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    if(n <=2) {return n}
    let floor1 = 1
    let floor2 = 2
    let sum = 0;
    for(let i =3; i<=n; i ++){
        sum = floor1 + floor2
        floor1 = floor2
        floor2 = sum
    }
    return sum
};
```