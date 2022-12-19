4ms 100% 100%

这道题其实是一个很明显的动态规划题目. 首先阶段性很明显--要按顺序依次转出需要的字符. 

假如我们用f[i][j]表示, 当转完前i个字符, 12点方向指向第j个字符时, 需要的最少步数.那么很简单地:
f[i][j] = min{f[i-1][k] + rotate(k,j) + 1}, 其中arr[k]必须等于arr[i-1], 即从上一个合法状态转移而来.

这里有个优化,我们可以提前记录下每个字符出现的下标, 这样可以不用每次遍历全部下标, 这样能够大大降低复杂度
同时只和i-1相关因此可以省掉一维

```rust
use std::collections::HashMap;

impl Solution {
    pub fn find_rotate_steps(ring: String, key: String) -> i32 {
        if ring.is_empty() || key.is_empty() {
            return 0;
        }
        let n = ring.len();
        let m = key.len();
        const MAX: usize = std::i32::MAX as usize;
        let mut f = vec![vec![MAX; n]; 2];
        let mut pos = HashMap::new();
        for (i, &c) in ring.as_bytes().iter().enumerate() {
            pos.entry(c).or_insert(vec![]).push(i);
        }
        let rs = ring.as_bytes();
        let ks = key.as_bytes();
        if let Some(arr) = pos.get(&ks[0]) {
            for &i in arr {
                f[1][i] = Self::calc(0, i, n) + 1;
            }
        }
        let mut idx = 0;
        for i in 1..m {
            let nidx = idx ^ 1;
            for j in 0..n {
                f[idx][j] = MAX;
                if rs[j] != ks[i] {
                    continue;
                }
                if let Some(pre) = pos.get(&ks[i-1]) {
                    for &k in pre {
                        f[idx][j] = f[idx][j].min(f[nidx][k] + Self::calc(j, k, n) + 1);
                    }
                }
            }
            idx = nidx;
        }
        let mut ans = std::i32::MAX as usize;
        for &v in f[idx^1].iter() {
            ans = ans.min(v);
        }
        ans as i32
    }
    fn calc(a: usize, b: usize, n: usize) -> usize {
        if a < b {
            (b-a).min(n-b+a)
        } else {
            (a-b).min(n-a+b)
        }
    }
}
```