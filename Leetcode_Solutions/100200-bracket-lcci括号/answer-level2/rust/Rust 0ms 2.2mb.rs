```rs
impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        // 用一个栈存储任务
        // 每个任务的结构是 (当前字符串, 左括号数量, 右括号数量)
        // 一开始栈中只有 ("(", 1, 0)
        let mut result = vec![("(".to_string(), 1, 0)];
        for _ in 1..n*2 {
            let mut old_result = vec![];
            std::mem::swap(&mut old_result, &mut result);

            for (s, l, r) in old_result {
                // 左括号数量大于右括号
                // 添加右括号
                if l > r {
                    let mut s1 = s.clone();
                    s1.push(')');
                    result.push((s1, l, r+1));
                }
                // 左括号数量小于总对数
                // 添加左括号
                if l < n {
                    let mut s2 = s.clone();
                    s2.push('(');
                    result.push((s2, l+1, r));
                }
            }
        }
        result.into_iter().map(|(s, _, _)| s).collect()
    }
}
```