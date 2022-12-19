### 解题思路
![image.png](https://pic.leetcode-cn.com/190023f2440b53a13820b350b59b54437aae6a4a5118039a1b71fbbdebb383e0-image.png)

没写，懒得写

### 代码

```rust
impl Solution {
    pub fn prefixes_div_by5(a: Vec<i32>) -> Vec<bool> {
        let mut result = Vec::with_capacity(a.len());
        let mut n = 0;

        for i in a {
            n <<= 1;
            n += i;
            result.push(n % 5 == 0);
            n %= 5;
        }
        result
    }
}
```