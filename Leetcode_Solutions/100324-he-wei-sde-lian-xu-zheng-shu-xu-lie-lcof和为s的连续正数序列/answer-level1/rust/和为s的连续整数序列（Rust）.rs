### 解题思路
暴力+枚举，代码如下

### 代码

```rust
impl Solution {
    pub fn find_continuous_sequence(target: i32) -> Vec<Vec<i32>> {
        let mut ans = vec![];
        let mut idx = 1;
        while idx < target {
            let mut v = vec![];
            let mut jdx = idx;
            let mut sum = 0;
            while sum < target {
                sum += jdx;
                v.push(jdx);
                jdx += 1;
            }
            if sum == target {
                ans.push(v);
            }
            idx += 1;
        }
        ans
    }
}
```