注意单纯fn不能capture外部变量， closure又不支持递归调用，所以只能写一个struct并将所有需要引用的环境变量包含进去。
```rust
const dash: [&'static str; 8] = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];
struct Generator<'a> {
    strs: &'a Vec<&'static str>,
    result: Vec<String>,
}

impl<'a> Generator<'a> {
    fn new(strs: &'a Vec<&'static str>) -> Self {
        Self {
            strs,
            result: Vec::with_capacity(3usize.pow(strs.len() as u32)),
        }
    }
    fn dfs(&mut self, prefix: String, depth: usize) {
        if depth == self.strs.len() {
            if (prefix.len() > 0) {
                self.result.push(prefix);
            }
            return;
        }
        let s = self.strs[depth];
        for b in s.chars() {
            self.dfs(format!("{}{}", prefix, b), depth + 1);
        }
    }
}
impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        let two = b'2';
        let strs = digits
            .bytes()
            .map(|x| dash[(x - two) as usize])
            .collect::<Vec<&'static str>>();
        let mut gen = Generator::new(&strs);
        gen.dfs("".into(), 0);
        gen.result
    }
}
```
