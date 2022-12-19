```rust
impl Solution {
    pub fn can_complete_circuit(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
        let mut gas_left = 0;
        let mut gas_left_min = 0;
        let mut gas_left_pos = -1;
        for i in 0..gas.len() {
            gas_left += gas[i] - cost[i];
            if gas_left < gas_left_min {
                gas_left_min = gas_left;
                gas_left_pos = i as i32;
            }
        }
        if gas_left >=0 {
            if gas_left_pos+1 < gas.len() as i32{gas_left_pos+1} else {0}
        } else {
            -1
        }
    }
}
```