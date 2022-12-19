假如我们做一个预处理, 把数组[1,1,1,2,2,3,3,2,2,2]变成 `[{val:1, len: 3}, {val:2, len:2}, {val:3, len:2}, {val:2, len:3}]`
针对预处理之后的block[i], 我们设f[i]表示第i个block作为结尾的最大长度.则有:
* f[i] = f[i-1]+block[i].len  (block[i].val == block[i-2].val)
* f[i] = block[i-1].len + block[i].len  (block[i].val != block[i-2].val)

因为当区块i和i-2的值相等时, 它们是可以拼在一起形成一个更大区块的.

当然, f[i]只和f[i-1]有关, 因此我们可以只使用两个变量来存储. 同时, 我们也只需要当前3个block的信息, 因此我们也只需要O(3)的空间来存储block, 并且边DP边计算block

```rust
    pub fn total_fruit_dp(tree: Vec<i32>) -> i32 {
        let n = tree.len();
        let mut i = 0;
        let mut j = i;

        // to begin, let's try to find the first two blocks
        while j < n && tree[j]==tree[i] {j+=1;}
        let mut ans = j-i;
        let mut pp = (tree[i], ans, ans); // pp stores the first block, but from the third block's point of view, it's prepre, so pp
        i = j;
        if i >= n {
            return ans as i32;
        }
        // find the second block
        while j < n && tree[j] == tree[i] {j+=1;}
        ans += j-i;
        let mut p = (tree[i], ans, j-i); // from the third block's point of view, it's pre, so p
        i = j;
        while i < n {
            let mut j = i;
            // find current block
            while j < n && tree[i] == tree[j] {j+=1;}
            let len = j-i;
            if tree[i] == pp.0 { // if value == block[i-2].value
                pp = p;
                p = (tree[i], pp.1+len, len);
                ans = ans.max(p.1);
            } else {
                pp = p;
                p = (tree[i], pp.2+len, len);
                ans = ans.max(p.1);
            }
            i = j;
        }
        ans as i32
    }
```
最终复杂度就是O(n)扫描+O(1)空间