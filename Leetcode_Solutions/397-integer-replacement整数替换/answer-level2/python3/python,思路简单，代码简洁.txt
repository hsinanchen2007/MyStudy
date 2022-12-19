每遇偶数除以2，没什么好说。
遇到奇数，应变换使其成为4的倍数，目的是使该数下一步变成能连续两次除以2的偶数
因此mod4==1时减1，mod4==3时加1
有个例外是3, 3——2——1 比 3——4——2——1更快
```
class Solution:
    def integerReplacement(self, n: int) -> int:
        count = 0
        while n>1:
            if n==3:
                n-=1
            elif n%4==1:
                n-=1
            elif n%4==3:
                n+=1
            else:
                n/=2
            count+=1
        return count
```
