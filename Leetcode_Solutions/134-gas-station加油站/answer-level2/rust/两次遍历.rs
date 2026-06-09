
执行用时 :196 ms, 在所有 Rust 提交中击败了100.00%的用户
内存消耗 :2.2 MB, 在所有 Rust 提交中击败了100.00%的用户

```
pub fn can_complete_circuit(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
    let mut gain;
    let len = gas.len();
    'outer: for i in 0..len{
        gain =0;
        for j in 0..len{
            let index = (i + j)%len;
            gain = gain + gas[index] - cost[index];
            if gain < 0 {
                continue 'outer;
            }
            
        }
        return i as i32;
    }
    -1
}
```
