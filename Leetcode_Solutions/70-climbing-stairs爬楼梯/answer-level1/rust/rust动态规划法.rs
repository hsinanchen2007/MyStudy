### 解题思路
利用斐波拉契数列实现动态规划，rust实现

### 代码

```rust
impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if n == 1{
            return 1;
        }
        
        let mut vec: Vec<i32> = Vec::new();
        for i in 1..n+1 {
            vec.push(0);
        }
        vec[0] = 1;
        vec[1] = 2;

        for s in 2..n as usize {
            let first: i32 = *(&vec[s-1]);
            let second: i32 = *(&vec[s-2]);
            let mut third: &mut i32 = &mut vec[s];
            *third = first + second;
        }

        *&vec[vec.len()-1]
    }
}
```