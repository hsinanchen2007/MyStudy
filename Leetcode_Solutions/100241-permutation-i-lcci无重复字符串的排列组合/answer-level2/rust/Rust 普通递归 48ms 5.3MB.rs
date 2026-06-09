```rs
impl Solution {
    pub fn permutation(s: String) -> Vec<String> {
        fn mutation(chars: Vec<char>) -> Vec<String> {
            if chars.is_empty() {
                vec!["".to_string()]
            } else {
                let mut r = vec![];
                for i in 0..chars.len() {
                    for mut s in mutation(chars[..i].iter().chain(chars[i+1..].iter()).map(|&x| x).collect::<Vec<char>>()).into_iter() {
                        s.push(chars[i]);
                        r.push(s);
                    }
                }
                r
            }
        }
        let chars = s.chars().collect::<Vec<_>>();
        mutation(chars).into_iter().collect()
    }
}
```