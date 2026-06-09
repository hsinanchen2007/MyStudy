### 运行结果

![image.png](https://pic.leetcode-cn.com/12e2d9bd6f3dc05f2b78b6f0f0f5abc9f237c4e598750c876bb93ea978fc540a-image.png)

### 解题思路
26进制转换为十进制

### 代码

```rust
impl Solution {
    pub fn title_to_number(s: String) -> i32 {
        let mut str_arr = s.bytes().collect::<Vec<_>>();
        let len = s.len();
        let mut res = 0i32;
        for i in 0..len {
            let tmp = str_arr[i] - 64;
            if i != (len - 1) {
                res = (res + tmp as i32) * 26;
            } else {
                res += tmp as i32;
            }
        }
        (res)
    }
}
```