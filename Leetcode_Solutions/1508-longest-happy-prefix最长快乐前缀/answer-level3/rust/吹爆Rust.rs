### 解题思路
这一题的思路没啥可以说的，直接从开头截取字符串依次匹配就好了。

那么如题，我是来吹爆Rust的，对于字符串匹配的优化可以说是很棒了，比我看到C的答案还要快一些。

执行用时 : 308 ms, 在所有 Rust 提交中击败了 100.00% 的用户
内存消耗 : 2.3 MB, 在所有 Rust 提交中击败了 100.00% 的用户

### 代码

```rust
impl Solution {
    pub fn longest_prefix(s: String) -> String {
        let  s_bytes = s.as_bytes();
        for i in 1..s.len() {
            if s.get(0..(s.len() - i)) == s.get(i..s.len()){
                return String::from(s.get(i..s.len()).unwrap());
            }
        }
        String::from("")
    }
    
}
```