### 解题思路
rust的dfs（？）
l：还需生成的左括号数量
r：还需生成的右括号数量，生成左括号后会+1
prefix：之前的字符（无关心）
如果lr均大于1，则复制一份下发
### 代码

```rust
impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        gp(n, 0, String::new()).collect()
    }
}
fn gp(l: i32, r: i32, prefix: String) -> Box<dyn Iterator<Item = String>> {
    match (l, r) {
        (0, 0) => Box::new(std::iter::once(prefix)),
        (l, 0) => Box::new(gp(l - 1, 1, prefix + "(")),
        (0, r) => Box::new(gp(0, r - 1, prefix + ")")),
        (l, r) => Box::new(gp(l - 1, r + 1, prefix.clone() + "(").chain(gp(l, r - 1, prefix + ")")))
    }
}

```