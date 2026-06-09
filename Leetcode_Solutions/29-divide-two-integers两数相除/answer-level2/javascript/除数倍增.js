## 第一版，利用减法循环暴力解，毫无意外的超时。
## 第二版，对除数倍增后再利用减法处理
> 84ms,34.7MB。
```javascript []
/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */
var divide = function(dividend, divisor, count = 1) {
  const absDividend = Math.abs(dividend);
  const absDivisor = Math.abs(divisor);
  const isMinus = (dividend === absDividend ? 1 : -1) ^ (divisor === absDivisor ? 1 : -1);
  let res = divideDichotomy(absDividend, absDivisor, 0);

  if (isMinus) res = -res;
  if (res > 2147483647) return 2147483647;
  if (res < -2147483648) return -2147483648;
  return res;
};

/**
 * @param {number} absDividend 被除数(非负数)
 * @param {number} originAbsDivisor 最初的除数(非负数)
 * @param {number} res 上一个部分得到的结果
 */
function divideDichotomy(absDividend, originAbsDivisor, res) {
  if (absDividend < originAbsDivisor) return res;
  let count = 1;
  let absDivisor = originAbsDivisor;
  while (absDividend >= absDivisor) {
    const nextAbsDivisor = absDivisor + absDivisor;
    if (absDividend === nextAbsDivisor) return count + count + res;
    if (absDividend < nextAbsDivisor) return divideTemp(absDividend - absDivisor, originAbsDivisor, res + count);
    absDivisor = nextAbsDivisor;
    count += count;
  }
}
```

### 思路
+ 利用异或运算先得到最终结果的符号，然后将被除数和除数全部转为非负数进行计算
+ divideDichotomy方法：
  1. 将除数 `absDivisor` 一直倍增直到除数下一次倍增将会大于被除数 `absDividend`
  2. 倍增同时计算最终的除数 `absDivisor` 与初始除数 `originAbsDivisor` 之间的倍数关系 `count` 即这一部分的最终结果
  3. 递归计算下一部分被除数 `absDividend - absDivisor` 与初始除数 `originAbsDivisor` 的整除结果
  4. 重复上述步骤直到剩余部分小于初始除数，每个部分的结果加起来就是最终的结果
示例：divide(11,3)
![image.png](https://pic.leetcode-cn.com/ecf5260c6014021c1b5a1f49498e090a23b94bbccccd3de69911b45ecd50f428-image.png)
+ 处理溢出值


### 如果觉得我的思路和代码还不错或者有看不懂的地方希望大家给我一点反馈哦。（感觉思路写的有点啰嗦了）`(..›ᴗ‹..)`

#### 应该还有优化的空间，计算倍增的时候存在重复计算