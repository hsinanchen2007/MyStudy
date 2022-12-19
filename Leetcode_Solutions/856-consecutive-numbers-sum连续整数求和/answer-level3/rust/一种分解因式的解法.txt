# 思路
## 平凡的解
显然对于每个数字都有一个平凡的解, 那就是这个数字本身就是一个解
## 非平凡解
考虑连续自然数m到n的和为
$$
S = \frac{(m+n)(n-m+1)}{2}
$$
设
$m+n = p,\qquad n-m+1=q$
则
$2S = pq$
有
$p+q-1 = 2n,\qquad p-q+1 = 2m$
那么对$2S$做因式分解, 当分解得到的$p,q$使得$p+q-1,p-q+1$为偶数时,则找到一对非平凡解
# 代码
## rust
```rust
pub fn consecutive_numbers_sum(s: i32) -> i32 {
        let mut count = 1;
        let double_s = s * 2;
        let mut p = 2;
        while p*(p+1) <= double_s {
        // p是否为2s的因子?
            if double_s%p == 0 {
                let q = double_s/p ;
                // m,n同时为偶数吗?
                if (p+q-1)%2 == 0 && (p-q+1)%2 == 0 {
                    count += 1;
                }
            }
            p += 1;
        }
        count
    }
}
```
