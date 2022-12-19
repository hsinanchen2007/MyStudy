
![image.png](https://pic.leetcode-cn.com/ce37e47b7e5d5277643605aa4e143864d74347c0e3f1556b57683295b724a53a-image.png)

方法一：朴素方法（笨办法，12ms）

满足2的幂的数判断条件是只有最高位是1，其余位都是0，比如 100,100000,10000000 等。

那么笨办法就是从低位一个一个判断，还不到最高位就遇到了1，那么肯定不是2的幂。

代码
```
func isPowerOfTwo(n int) bool { // 迭代判断
    for n!=1 && n!=0 {
        if n&1==1 {
            return false
        }
        n >>= 1
    }
    if n==1 {
        return true
    }
    return false
}
```

方法二：直接判断（0ms）

判断 n & (n-1) 是否为0即可……

如果是 1000,那么计算 1000 & 0111 = 0，所以是2的幂

代码
```
func isPowerOfTwo(n int) bool { // 神仙方法
    if n!=0 && n&(n-1) == 0 {
        return true
    }
    return false
}
```