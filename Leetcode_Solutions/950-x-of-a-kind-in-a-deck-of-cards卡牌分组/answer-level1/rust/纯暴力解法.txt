

### 代码

```rust
impl Solution {
    pub fn has_groups_size_x(deck: Vec<i32>) -> bool {
        let mut nums: Vec<i32> = (1..=10000).map(|_| 0).collect();
        let length = deck.len();
        for (_,v) in deck.iter().enumerate(){
            nums[*v as usize]+=1;
        }
        for i in (2..=length) {
            if length%i==0{
                if nums.iter().all(|&x| x%(i as i32) == 0){
                    return true
                }
            }
        }
        false
    }
}
```