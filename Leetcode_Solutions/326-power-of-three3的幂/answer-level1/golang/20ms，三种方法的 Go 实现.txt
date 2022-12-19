
![image.png](https://pic.leetcode-cn.com/d83de9473ff095b748cc8d408cfcf52353e0c9756212f171f0c55bb9ebe4febb-image.png)


方法一：累除法（44ms）

将 n 累除 3，如果累除过程中的数不能被 3 整除了，说明 n 不是 3 的幂
```
func isPowerOfThree(n int) bool {
    if n==0 {
        return false
    }
    for n!=0 && n!=1 {
        if n%3!=0 {         // 遇到不能整除 3 的情况，说明就不是3的幂
            return false
        }
        n /= 3
    }
    return true
}
```

方法二：累乘法（20ms）

思路和累除法类似，从 1 开始累乘 3，看是否能正好遇到 n，如果超过了 n，那么说明 n 不是 3 的幂

代码看起来简介一些：
```
func isPowerOfThree(n int) bool {
    i := 1
    for ; i<n; i*=3 {   // 从 1 累乘 3 看能不能正好得到 n，如果超出了 n，那么说明 n 不是 3 的幂
    }
    if i==n {
        return true
    }
    return false
}
```

方法三：直接求，神仙方法（44ms）

这个方法看了大佬的题解，因为整数范围内的3的幂次最大是 1162261467，所以用 1162261467 对 n 求模，如果等于0，说明 n 是 3 的幂。

不过按理说这个方法速度最快来着，怎么就跑不过方法二呢。

```
func isPowerOfThree(n int) bool {
    return n>0 && 1162261467%n==0
}
```