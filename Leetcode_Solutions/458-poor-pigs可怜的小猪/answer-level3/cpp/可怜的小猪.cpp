一只猪最多喝 `(int) p/m` 次水，

那么总共有第一次喝就死，第二次喝就死，...，第 `p/m` 次喝死，喝到最后都没死，共 `p/m +1` 种情况，

那么 $x$ 只猪的信息量等价于一个 $x$ 位的 `p/m+1` 进制数，即 `pow(p/m+1,x)`，确认毒药在哪的信息量为 $n$，那么有 `pow(p/m+1,x) >= n`，`x >= log(n) / log(p/m+1)`

返回结果向上取整
```C++ []
class Solution {
public:
    int poorPigs(int n, int m, int p) {
        //
        double times = p/m;
        double radius = times+1;
        // radius^x >= n 
        // x>= log(n)/log(radius)
        double x = log(n)/log(radius);
        return (int)ceil(x);
    }
};
```
