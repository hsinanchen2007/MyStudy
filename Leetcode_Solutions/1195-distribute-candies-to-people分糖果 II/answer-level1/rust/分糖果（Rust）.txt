### 解题思路
暴力模拟循环

### 代码

```rust
impl Solution {
    pub fn distribute_candies(candies: i32, num_people: i32) -> Vec<i32> {
        let mut cnt = candies;
        let mut candie = 1;
        let mut idx = 0;
        let mut ans = vec![0;num_people as usize];
        while cnt > 0 {
            idx = idx%num_people;
            if cnt > candie {
                ans[idx as usize] += candie;
            } else if cnt == candie {
                ans[idx as usize] += candie;
                break;
            } else {
                ans[idx as usize] += cnt;
                break;
            }
            cnt -= candie;
            candie += 1;
            idx += 1;
        }
        ans
    }
}
```