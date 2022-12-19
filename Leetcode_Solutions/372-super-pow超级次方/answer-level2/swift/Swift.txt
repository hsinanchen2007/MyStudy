1.主要利用了两个求模等式，在较早的时机球模，防止数字过大导致栈溢出。
    //a^b %p = ((a%p)^b) % p  公式1
    //(a*b) %p = (a%p * b%p) %p 公式2
    // mod = 1337
2.在对指数的降低上,即b数组的降低。可以假设 求解a^1372,将式子展开
a^1372 = a^1000 * a^300 * a^70 * a^2
       = (a^1000)^1 * (a^100)^3 * (a^10)^7 * a^2
可以先用公式1，然后利用前一低位的圆括号中的数来表示，比如用(a^100)^10 来表示a^1000就可以对a^100部分求模了。

```
let mod = 1337
    
    func superPow(_ a: Int, _ b: [Int]) -> Int {
        var ret = 1
        var modNumber = a
        for i in 0 ... b.count-1 {
            ret = (ret * qpow(x: modNumber, n: b[b.count-1-i])) % mod
            modNumber = qpow(x: modNumber%mod, n: 10) % mod
        }
        return ret
    }
    
        func qpow(x:Int, n:Int) -> Int {
        var r = 1
        var m = n
        var base = x%mod
        while m > 0 {
            if (m & 1) > 0 {
                r = (r * base) % mod
            }
            base = (base * base) % mod
            m = m >> 1
        }
        return r
    }
```
