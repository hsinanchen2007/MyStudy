### 解题思路
1. 构造二分搜索区间
2. 使用容斥原理计数
3. 注意边界条件, 如果返回Mid, 需要进行`mid-min({mid%a, min%b, min%c})`调整

### 代码

```c++ []
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        // 二分法+容斥原理
        // C++17标准中<numeric>库集成了最大公约数(lcm)和最小公倍数的函数(gcd)
        long lcm_ab = lcm<long>(a, b);
        long lcm_ac = lcm<long>(a, c);
        long lcm_bc = lcm<long>(b, c);
        long lcm_abc = lcm<long>(lcm_ab, c);

        // 构造搜索区间
        int left = min({a, b, c});
        int right = min((int)(2*pow(10, 9)+1), left*n);

        // 二分搜索区间, 使用容斥原理计数
        while(left < right){
            int mid = left + (right-left)/2;
            // 计算[left, mid)区间中丑数的数量
            int N = mid/a + mid/b + mid/c - mid/lcm_ab - mid/lcm_ac - mid/lcm_bc + mid/lcm_abc;
            if(N < n){
                left = mid+1;
            }
            else
                right = mid;
        }

        return left;
    }

private:
    int _gcd(int x, int y){
        assert(x>0 && y>0);
        if(x%y == 0)
            return y;
        return _gcd(y, x%y);
    }

    int _lcm(int x, int y){
        return x*y/_gcd(x, y);
    }
};
```
```java []
class Solution {
    public int nthUglyNumber(int n, int a, int b, int c) {
        int l = Math.min(a, Math.min(b, c));
        int r = Math.min(l*n, 2*(int)Math.pow(10, 9)+1);
        
        long lcm_ab = lcm(a, b);
        long lcm_ac = lcm(a, c);
        long lcm_bc = lcm(b, c);
        long lcm_abc = lcm(lcm(a,b), c);
        
        // 进行二分搜索, 使用容斥原理计数
        while(l < r){
            int mid = l+((r-l)>>1);
            int N = mid/a+mid/b+mid/c-(int)(mid/lcm_ab+mid/lcm_ac+mid/lcm_bc-mid/lcm_abc);
            if(N < n)
                l = mid+1;
            else
                r = mid;
        }

        return l;
    }

    private long gcd(long x, long y){
        if(x%y == 0)
            return y;
        return gcd(y, x%y);
    }

    private long lcm(long x, long y){
        return x*y/gcd(x,y);
    }
}
```
```python []
class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        def gcd(x, y):
            if x%y == 0:
                return y
            return gcd(y, x%y)

        def lcm(x, y):
            return x*y//gcd(x,y)

        l = min(a,b,c)
        r = min(int(2*pow(10, 9)+1), l*n)
        lcm_ab, lcm_ac, lcm_bc, lcm_abc = lcm(a,b), lcm(a,c), lcm(b,c), lcm(lcm(a,b), c)

        while l<r:
            mid = l+(r-l)//2
            N = mid//a+mid//b+mid//c-mid//lcm_ab-mid//lcm_ac-mid//lcm_bc+mid//lcm_abc
            if N<n:
                l = mid+1
            else:
                r = mid
        return l
    
```