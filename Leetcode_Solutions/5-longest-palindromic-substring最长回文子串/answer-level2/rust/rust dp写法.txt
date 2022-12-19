```
impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let len_s = s.len();
        if len_s < 2 {
            return s;
        }
        let mut dp: Vec<Vec<bool>> = vec![vec![false; len_s]; len_s];
        let mut s = s.as_bytes();
        let mut ret_s = String::from_utf8(vec![s[0]]).unwrap();
        for r in 1..len_s{
            for l in 0..r {
                if s[l] == s[r] && ( r - l + 1 <= 3 || dp[l+1][r-1]) {
                    dp[l][r] = true;
                    if r - l + 1 > ret_s.len() {
                        ret_s = String::from_utf8(s[l..r+1].to_vec()).unwrap();
                    }
                }
            } 
        }
        ret_s
    }
}
```
