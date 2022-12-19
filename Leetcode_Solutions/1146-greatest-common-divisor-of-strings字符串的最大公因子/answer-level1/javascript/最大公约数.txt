# gcd 最大公约数

## 介绍

辗转相除 或 更相减损。

```js
// 辗转相除法: 两个整数的最大公约数为较小的数与他们相除余数的最大公约数
function gcd(a, b) {
  return b === 0 ? a : gcd(b, a % b);
}
```

ref:
- [https://www.bilibili.com/video/av53438290/](https://www.bilibili.com/video/av53438290/?spm_id_from=333.788.videocard.0)

- [https://zhuanlan.zhihu.com/p/31824895](https://zhuanlan.zhihu.com/p/31824895)

# case

- [https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/](https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/)
