### 解题思路
//最后一步： 关注最优策略中最后一段回文串，设为S[j..N-1]
//需要知道S前j个字符[0..j-1]最少可以划分成几个回文串
//子问题
//状态：设S前i个字符S[0..i-1]最少可以划分成F[i]个回文串
//转移方程 F[i] = Min<j=0,....,i-1>{F[j]+1 && S[j..i-1]是回文串}
//        F[i] = Min<j=0,....,i-1>{F[j]+1 && palin_dp[j][i-1]= true}
//答案是F[n]-1,因为是问最少分割几次，而不是最少分割成多少个

### 代码

```rust
impl Solution {
    pub fn min_cut(s: String) -> i32 {
        let n = s.len();
        if n==0 {
            return 0;
        }
        let mut f = vec![0; n+1];
        let chars = s.chars().collect::<Vec<char>>();
        let palin_dp = get_palindrome_dp(&chars);
        for i in 1..=n {
            f[i] = i32::max_value();
            for j in 0..i {
                if palin_dp[j][i-1] && f[j]+1 < f[i] {
                    f[i] = f[j]+1;
                }
            }
        }
        f[n]-1
    }
}

//判断l~j之间的字符串是否回文串
pub fn get_palindrome_dp(chars: &Vec<char>) -> Vec<Vec<bool>> {
    let n = chars.len();
    let mut dp = vec![vec![false; n]; n];
    let n = n as i32;
    for i in 0..n {
        //奇数
        let (mut l, mut r) = (i, i);
        while l>=0 && r<n && chars[l as usize] == chars[r as usize] {
            dp[l as usize][r as usize] = true;
            l -= 1;
            r += 1;
        }

        //偶数
        let (mut l, mut r) = (i, i+1);
        while l>=0 && r<n && chars[l as usize] == chars[r as usize] {
            dp[l as usize][r as usize] = true;
            l -= 1;
            r += 1;
        }
    }
    dp
}
```