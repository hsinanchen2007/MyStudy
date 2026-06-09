该问题和矩阵乘法类似。
我们可以把这个表达式构建成一棵语法树，例如`1|0`，则可以以`|`为根，`1`和`0`作为子节点。对于复杂的表达式，可以构建很多棵树，每个子树代表了一个大括号。

所以对于某个表达式`E`,可以构建很多树`T1, T2, ... T_N`, 那么结果就是`ans = sum(combination(T_i.left, T_i.right, op[i]))`。

可见这可以递归解决，而且可以将子问题缓存起来。

所以定义`dp[i][j][value]`，代表表达式`E[i:j]`值为`value`的括号组合数，所以上面的`combination`函数就可以有：例如`&`: `dp[i][j][0] = sum(dp[i][k][0] * dp[k+1][j][0] + dp[i][k][0] * dp[k+1][j][1] + dp[i][k][1] * dp[k+1][k][0])`，`|`和`^`也可以得到类似的结果。

解可以从顶向下（递归+缓存），也可以从底向上（循环，先计算小的子表达式的结果），下面是从底向上的解：

```rust
impl Solution {
    pub fn count_eval(s: String, result: i32) -> i32 {
        let str = Vec::from(s.as_str());
        let len = str.len();
        // dp[i][j].0 means the count of combination with result 0 in range [i,j]
        // i here in str index is i * 2 for oprand, i * 2 + 1 for operator
        let mut dp = vec![vec![(0, 0); len / 2 + 1]; len / 2 + 1];

        for diff in 0..(len / 2 + 1) {
            let mut start = 0;
            while start + diff < len / 2 + 1 {
                let end = start + diff;
                if diff == 0 {
                    if str[start * 2] == '1' as u8 {
                        dp[start][start].1 = 1;
                    } else {
                        dp[start][start].0 = 1;
                    }
                } else {
                    for i in start..end {
                        let op = str[i * 2 + 1] as char;
                        match op {
                            '&' => {
                                dp[start][end].0 += dp[start][i].1 * dp[i + 1][end].0
                                    + dp[start][i].0 * dp[i + 1][end].0
                                    + dp[start][i].0 * dp[i + 1][end].1;
                                dp[start][end].1 += dp[start][i].1 * dp[i + 1][end].1;
                            }
                            '|' => {
                                dp[start][end].1 += dp[start][i].1 * dp[i + 1][end].0
                                    + dp[start][i].1 * dp[i + 1][end].1
                                    + dp[start][i].0 * dp[i + 1][end].1;
                                dp[start][end].0 += dp[start][i].0 * dp[i + 1][end].0;
                            }
                            '^' => {
                                dp[start][end].0 += dp[start][i].0 * dp[i + 1][end].0
                                    + dp[start][i].1 * dp[i + 1][end].1;
                                dp[start][end].1 += dp[start][i].0 * dp[i + 1][end].1
                                    + dp[start][i].1 * dp[i + 1][end].0;
                            }
                            _ => {}
                        }
                    }
                }
                start += 1;
            }
        }
        
        return if result == 1 {
            dp[0][len / 2].1
        } else {
            dp[0][len / 2].0
        }
    }
}
```
