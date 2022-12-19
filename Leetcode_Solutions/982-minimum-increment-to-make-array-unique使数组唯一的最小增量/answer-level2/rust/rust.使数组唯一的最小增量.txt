### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn min_increment_for_unique(a: Vec<i32>) -> i32 {
        let mut arr=a;
        arr.sort();
        let mut res:i32 = 0;
        for i in 1..arr.len(){
            if arr[i]<=arr[i-1] {
                res += arr[i-1]-arr[i]+1;
                arr[i] = arr[i-1]+1;
            }
        }
        res
    }
}
```