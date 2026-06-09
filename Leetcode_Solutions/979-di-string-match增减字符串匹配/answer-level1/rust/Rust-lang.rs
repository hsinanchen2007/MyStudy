### 运行结果

![image.png](https://pic.leetcode-cn.com/098c615405d269ba2116eb9ce06a403dcb784a873f8fd9146dcebb02fe4dec48-image.png)

### 代码

```rust
impl Solution {
    pub fn di_string_match(s: String) -> Vec<i32> {
        let len = s.len();
        let mut ans = vec![];
        let mut max = len as i32;
        let mut min = 0i32;

        let str_arr = s.chars().collect::<Vec<_>>();
        for index in 0..len {
            if 'I' == str_arr[index] {
                ans.push(min);
                min += 1;
            } else {
                ans.push(max);
                max -= 1;
            }
        }
        ans.push(max);

        (ans)
    }
}
```

### 算法复杂度

**空间复杂度：O(n)**

**时间复杂度：O(n)**