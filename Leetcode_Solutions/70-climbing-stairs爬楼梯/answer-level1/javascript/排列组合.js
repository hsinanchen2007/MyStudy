## 第一版，假装这是一个排列组合问题
> 72ms,33.6M。
```javascript []
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
  let total = 0;
  for (let i = 0,j = n; j >= 0; j -= 2, i++) {
    total += combine(i, j);
  }
  return total;
};

/**
 * @name 组合计算公式 C(m,n)
 */
function combine(m, n) {
  if (m < n) [m, n] = [n, m];
  let count = 1;
  for (let i = m + n, j = 1; i > m; i--) {
    count *= i;
    if (j <= n) count /= j++;
  }
  return count;
}
```
## 思路：
1. 设`n`个台阶可以走`i`次1阶和`j`次2阶走到楼顶 → `i + 2 * j = n`
2. 遍历`i`和`j`的所有正整数解，例如`n = 4`时，`[i, j]`有`[0,2], [2, 1], [4, 0]`三种可能
3. `i`次1阶和`j`次2阶时共可以组成`C(i, j) = (i + j)! / (i! * j!)`种组合，例如`n = 4`时有以下5种方法
    + `i = 0, j = 2`时，有`[2,2]`一种组合
    + `i = 2, j = 1`时，有`[1,1,2], [1,2,1], [2,1,1]`三种组合
    + `i = 4, j = 0`时，有`[1,1,1,1]`一种组合

## 第二版，递归方法，参考 [官方题解](https://leetcode-cn.com/problems/climbing-stairs/solution/pa-lou-ti-by-leetcode) 和 [大佬的题解](https://leetcode-cn.com/problems/climbing-stairs/solution/javascript-pa-lou-ti-by-rhinoc)
> 需要注意的是如果这里不使用记忆化递归的话真的会超时

## 第三版，斐波那契数列，看题解之前我真的没发现这里竟然是斐波那契数列，递归、循环都可以，方法太多就不说了。