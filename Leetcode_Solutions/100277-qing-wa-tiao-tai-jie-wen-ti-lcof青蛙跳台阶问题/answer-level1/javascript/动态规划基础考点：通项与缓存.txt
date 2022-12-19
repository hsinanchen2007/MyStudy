### 解题思路

第0个台阶f(0) ：1  （不跳）
第1个台阶f(1) ：1  （跳1次）
第2个台阶f(2) ：2  （跳1，1或者2）
第3个台阶f(3) ：两种情况，最后跳1或者跳2，
               最后跳1：上一个台阶是2，有f(2)种
               最后跳2：上一个台阶是1，有f(1)种
第n个台阶 ：两种情况，最后跳1或者跳2
          最后跳1：上一个台阶是n-1，有f(n-1)种
          最后跳2：上一个台阶是n-2，有f(n-2)种

通项公式 ：f(n) = f(n-2) + f(n-1)

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var numWays = function(n) {
    const mem=[1,1,2];
    for(let i = 3; i <= n ; i++){
        mem.push((mem[i-2]+mem[i-1])%1000000007)
    }
    return mem[n]
};

```