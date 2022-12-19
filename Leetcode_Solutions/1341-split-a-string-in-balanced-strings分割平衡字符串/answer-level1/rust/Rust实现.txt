### 运行结果
![image.png](https://pic.leetcode-cn.com/efaf954ed642c1d2eb83c9f1a6c3e1f36452b5ff4fb7c56724ff85c1e91264e1-image.png)

### 解题思路
None

### 代码

```rust
impl Solution {
    pub fn balanced_string_split(s: String) -> i32 {
        let mut count = 0i32;
        let mut l_flag = 0i32;
        let mut r_flag = 0i32;

        for c in s.chars() {
            match c {
                'L' => l_flag += 1,
                'R' => r_flag += 1,
                _ => return -1,
            }

            if l_flag == r_flag {
                count += 1;
                l_flag = 0;
                r_flag = 0;
            }
        }

        (count)
    }
}
```