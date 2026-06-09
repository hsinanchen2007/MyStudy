## 解题思路
定义一个变量 res 记录最少的操作次数。还需要一个变量 prev: Option<i32> 表示遍历数组时，当前数组许可的最小的唯一值。

首先数组排序。然后遍历数组，第一个数赋值给 prev，以后的每个数都要跟 prev 里的值 v 对比，如果 <= v，那么 res 要增加操作次数，v 则增加 1；如果 > v，就把那个数赋值给 prev. 遍历结束，返回 res 即可。

## 完整代码
```Rust
impl Solution {
    fn min_increment_for_unique(mut a: Vec<i32>) -> i32 {
        let mut res = 0;
        a.sort_unstable();
        let mut prev: Option<i32> = None;
        for val in a {
            if let Some(v) = prev {
                if val <= v {
                    res += v + 1 - val;
                    prev = Some(v + 1);
                } else {
                    prev = Some(val);
                }
            } else {
                prev = Some(val);
            }
        }
        res
    }
}
```