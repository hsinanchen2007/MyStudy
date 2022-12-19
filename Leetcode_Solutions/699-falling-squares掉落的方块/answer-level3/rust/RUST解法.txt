### 解题思路
1. 当前下落矩形与已稳定矩形不相交，则最大高度MAX_H不变
2. 故问题分为两步：
    a. 求取所有可能与当前下落矩形相交的所有情况下的高度，（高度 = 相交情况下已稳定的高度 + 当前下落的边长），并取高度的最大值h
    b. 取a中求得的相交最大高度与当前最大高度的最大值，即MAX_H = max(h, MAX_H)

### 代码

```rust
impl Solution {
    pub fn falling_squares(positions: Vec<Vec<i32>>) -> Vec<i32> {
        
        if positions.is_empty() {
            return vec![];
        }

        let mut heights: Vec<i32> = Vec::new();
        let mut cur: Vec<i32> = Vec::new();
        
        let mut max_h = positions[0][1];
        cur.push(max_h);
        heights.push(max_h);

        let mut i = 1;
        while i < positions.len() {
            let mut h = positions[i][1];
            let mut j = i;
            while j > 0 {
                //不相交的情况 h = 当前下落矩形的长
                //求在所有已稳定矩形与当前下落矩形相交情况下的高度，并取其最大值入栈
                if !(positions[j-1][0] >= positions[i][0] + positions[i][1] || positions[i][0] >= positions[j-1][0] + positions[j-1][1]){
                    if cur[j-1] + positions[i][1] > h {
                        h = cur[j-1] + positions[i][1];
                    }
                }
                j -= 1;
            }
            cur.push(h);
            if h > max_h {
                max_h = h;
            }
            heights.push(max_h);
            i += 1;
        }
        heights
    }
}
```