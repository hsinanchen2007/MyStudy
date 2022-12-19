### 解题思路
![IMG_5C5CDBA84792-1.jpeg](https://pic.leetcode-cn.com/f43733bd058f8b2a027869fda9f5e10fba9a153f4c1509225ad19d6af521ca48-IMG_5C5CDBA84792-1.jpeg)
这里要考虑n的两种特殊可能-1，0
只要给出`f(-1)`和`f(0)`递推公式就可以计算其余的所有解，避免重复计算，用一个哈希表保存算过的结果。

### 代码

```golang
func myPow(x float64, n int) float64 {
    note:=make(map[int]float64)
    var f func(n int)float64
    f=func(n int)float64{
        if n==0{
            return 1
        }else if n==-1{
            return 1/x
        }
        v,have:=note[n]
        if have{
            return v
        }
        if n%2==0{
            res:=f(n/2)*f(n/2)
            note[n]=res
            return res
        }else{
            res:=f((n-1)/2)*f((n-1)/2)*x
            note[n]=res
            return res
        }
    }
    return f(n)
}
```