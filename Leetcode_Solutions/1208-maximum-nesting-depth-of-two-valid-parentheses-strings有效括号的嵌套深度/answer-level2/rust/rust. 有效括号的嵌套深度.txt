### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn max_depth_after_split(seq: String) -> Vec<i32> {
        let mut ans:Vec<i32> = Vec::new();
        let mut d = 0;
        for c in seq.chars(){
            match c{
                '(' => {
                    d += 1;
                    ans.push(d%2);
                }
                ')' => {
                    ans.push(d%2);
                    d -= 1;
                }
                _ =>{
                    return vec![];
                }
            }
        }
        ans
    }
}



```