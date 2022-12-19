### 解题思路
此处撰写解题思路
//先按长度从小到大排序
//F[i] = Max(1, F[i]+1 && E[i]可以放下E[j])
### 代码

```rust
impl Solution {
    pub fn max_envelopes(envelopes: Vec<Vec<i32>>) -> i32 {
        if envelopes.len() == 0  {
            return 0;
        }
        let mut envelopes = envelopes;
        //按长度排序
        envelopes.sort_by(|a, b| a[0].partial_cmp(&b[0]).unwrap());
        let mut f = vec![0; envelopes.len()];
        let mut r = 0;
        for i in 0..envelopes.len() {
            //初始化数据
            f[i] = 1;
            for j in 0..i {
                //长度、宽度满足
                if envelopes[j][1] < envelopes[i][1] 
                    && envelopes[j][0] < envelopes[i][0]
                    //状态转移条件
                    && f[j]+1 > f[i] {
                    f[i] = f[j]+1;
                }
            }
            r = r.max(f[i]);
        }
        r
    }
}
```