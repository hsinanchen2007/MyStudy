直接看一个例子：

`2 1 1 2 3 4`，我们观察最后一个数4，看看如果以4结尾有多少个等差数列。

仔细分析有两种情况：

* 之前本身就是等差数列 `. . 1 2 3`和`. 1 . 2 3`，4刚好可以放到3后面，成为新的等差数列 `. . 1 2 3 4`和`. 1 . 2 3 4`
* 之前本来没有等差数列，但是由于4的加入形成了等差数列，比如`2 . . . 3 4`和 `. . . 2 3 4`。

设f[i][d]表示以a[i]结尾公差为d的等差数列个数

设g[i][d]表示以与a[i]的差为d的数的个数

所以可以发现：
`f[i][d] = sum{ f[j][d] + g[j][d] }  (j∈[0,i)  ,a[i]-a[j] == d)`
`g[i][d] = count( a[i]-a[j] == d)`

这里有个优化，  由于`f[i][d] = sum{f[j][d] + g[j][d]}`，而g[i][d]的求解和f[i][d]无关，所以我们可以用w[i][d]来表示f[i][d]+g[i][d]。因此：
`w[i][d] = sum{ w[j][d] } (j∈[0,i)  ,a[i]-a[j] == d) + count(a[i]-a[j] == d)`。这里需要注意的就是w[i][d]并不是以a[i]结尾公差为d的等差数列个数，总数需要在计算过程中累加。

代码如下：
更新HashMap的一个部分依赖于HashMap另一个部分的值时，由于rust的ownership导致写起来很蛋疼，当然性能会有些损耗，这是rust的局限性。

由于测试数据比较鸡贼，需要防止计算公差时溢出，数据类型需要选用i64
```rust
use std::collections::HashMap;

impl Solution {
    pub fn number_of_arithmetic_slices(a: Vec<i32>) -> i32 {
        let mut ans = 0;
        let n = a.len();
        let mut dp:HashMap<usize, HashMap<i64, i32>> = HashMap::new();
        for i in 1..n {
            for j in 0..i {
                let d = a[i] as i64 - a[j] as i64;
                let mut pre = 0;
                if let Some(v) = dp.get(&j) {
                    if let Some(&v) = v.get(&d) {
                        ans += v;
                        pre = v;
                    }
                }
                let t = dp.e***y(i)
                    .or_insert(HashMap::new()).e***y(d)
                    .or_insert(0);
                *t += 1+pre;
            }
        }
        ans
    }
}
```