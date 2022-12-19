![image.png](https://pic.leetcode-cn.com/a8730ca35e4207d86a646a3f8796c329a0efe933187ef03074b9fc1ecd3a0774-image.png)

```rust
impl Solution {
    pub fn distribute_candies(candies: Vec<i32>) -> i32 {
        let mut backet = vec![0;200001];
        let len = candies.len() as i32;
        let lim = 100000;
        for candy in candies {
            backet[(candy + lim) as usize] = 1;
        }
        
        let mut diff_len = 0;
        
        for n in backet {
            if n != 0 { diff_len += 1; }
        }
        
        std::cmp::min(diff_len, len / 2)
    }
}
```
