### 解题思路
此处撰写解题思路

### 代码

```rust []
impl Solution {
    pub fn find_continuous_sequence(target: i32) -> Vec<Vec<i32>> {
        let mut res:Vec<Vec<i32>> = Vec::new();
        let mut sum = 3;
        let mut l= 1;
        let mut r = 2;
        
        while l < (target+1)/2{
            if sum < target{
                r += 1;
                sum += r;
            }else if target < sum{
                sum -= l;
                l += 1;
            }else{
                let mut tmp:Vec<i32> =  Vec::new();
                for i in l..r+1{
                    tmp.push(i);
                }
                res.push(tmp);
                sum -= l;
                l += 1;
            }
        }
        res
    }
}
```