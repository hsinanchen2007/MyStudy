# 7.整数反转

https://leetcode-cn.com/problems/reverse-integer/

## 分析

- 反转数字，123 -> 321，-123 -> 321，120 -> 21
- 如果首位是 0，忽略，如果是 负数，转换后还是 负数
- 数值范围 [−2^31, 2^31 − 1]，超出返回 0

## 解

### 1.转成字符串再转回数字

- 都当成 正整数 处理，记录 负号，转成 string，从后往前 取值
- 如果是 0，直接返回
- 如果 <0，记录 prefix='-'
- 调用 Math.abs 忽略正负，转成 string
- 遍历，i，**_O(logn)_**

  - 每次 从后往前 取值累加

- T **_O(logn)_**
  > 复杂度(n) 等于 位数(d) ，几位数就遍历几次，n=d  
  >  位数 d 是 以 10 为底的指数  
  >  e.g. 3 位数不管是几，都等同于 100，只遍历 3 次  
  >  [100, 999]=100=10^2=10^(3-1)  
  >  x=10^(d-1) -> d-1=log(10)x -> n=d=1+log(10)x  
  >  复杂度为 对数级
- S **_O(1)_**

```js
const reverse = function (x) {
  if (x === 0) return 0

  let prefix = ''
  if (x < 0) prefix = '-'

  const str = String(Math.abs(x))
  const len = str.length
  let i = len - 1
  let reStr = ''
  while (i >= 0) {
    reStr += str[i]
    i--
  }
  const res = Number(prefix + reStr)

  if (res < (-2) ** 31 || res > 2 ** 31 - 1) return 0
  return res
}
```

### 2.取余数

- 十进制算法，`x=a*10^n+b*10^(n-1)+...+c*10^0`
- `123=1*10^2+2*10^1+3*10^0`
- 所以用 x 除以 10 取余数，下一次循环 x=x/10 的整数部分，直到最后一位/10=0.n，取整后=0，停止循环
- 反转运算需要判断是否溢出
  > 1.溢出条件，res >= max / 10  
  > 2.res > max，一定溢出  
  > 3.res = max，mod > 7 一定溢出  
  > 7 或 8 是因为最大值 2 的 31 次方是 2147483648，最小值负 2 的 31 次方减一是-2147483647，这两个数值的个位数是 7 和 8

```js
const MAX = 2 ** 31 - 1
const MAX_MOD = MAX % 10
const MIN = (-2) ** 31
const MIN_MOD = MIN % 10

const reverse = function (x) {
  if (x === 0) return 0

  let start = x
  let res = 0

  while (start !== 0) {
    const mod = start % 10
    start = parseInt(start / 10)

    // 判断是否溢出 start
    if (res > MAX / 10 || (res === MAX / 10 && mod > MAX_MOD)) return 0
    if (res < MIN / 10 || (res === MIN / 10 && mod < MIN_MOD)) return 0
    // 判断是否溢出 end

    res = res * 10 + mod
  }

  return res
}
```
