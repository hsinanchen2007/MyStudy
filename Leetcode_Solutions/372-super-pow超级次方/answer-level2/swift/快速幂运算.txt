[Pow(x,n)](https://leetcode-cn.com/problems/powx-n/) 的升级版，主要用到了以下公式：

```
(a * b) % p = (a % p * b % p) % p
a ^ b % p = ((a % p) ^ b) % p
```

以 `3 ^ 1234` 为例，`3 ^ 1234 = 3 ^ 1000 * 3 ^ 200 * 3 ^ 30 * 3 ^ 4`，分解完成后每一部分使用快速幂求解。

```swift
class Solution {
    func superPow(_ a: Int, _ b: [Int]) -> Int {
        let mod = 1337
        var base = a % mod
        var ans = 1, x = base
        
        b.reversed().forEach { bit in
            ans = (ans * qpow(x, bit, mod)) % mod
            x = qpow(x, 10, mod) % mod
        }
        
        return ans
    }
    
    func qpow(_ base: Int, _ exponent: Int, _ mod: Int) -> Int {
        var ans = 1
        var base = base, exponent = exponent
        
        while exponent > 0 {
            if exponent & 1 == 1 {
                ans = (base * ans) % mod
            }
            base = (base * base) % mod
            exponent >>= 1
        }
        
        return ans
    }
}
```