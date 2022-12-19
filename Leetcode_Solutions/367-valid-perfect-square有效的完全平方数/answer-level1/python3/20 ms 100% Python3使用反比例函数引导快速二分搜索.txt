使用二分法搜索的本质就是两个端点逐步逼近的nums根的过程，那么有没有一种手段可以避免溢出并且快速收敛呢，这里就可以使用反比例函数对搜索过程进行引导。
定义一个反比例函数
```
y = nums / x
```
根据其对称性可知，对任意正数x1，对应的y1，nums的平方根必定落在(x1, y1)的区间之内，如此一来经过几次收敛之后就可以快速缩小根所在的区间。当区间长度等于1时，再做严格检验就可以了。
整体下来代码也非常简单：
```
def isPerfectSquare(self, num: int) -> bool:
        if num == 1:
            return True

        il = 2
        ir = num // 2

        # 二分法
        while ir - il > 1:
            mid = (il + ir)>> 1
            div_mid = num // mid
            il = min(mid, div_mid)
            ir = max(mid, div_mid)
        return num == il * il
```

