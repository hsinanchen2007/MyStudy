```
// 哈希方法
// use std::collections::HashMap;
// impl Solution {
//     pub fn find_repeat_number(nums: Vec<i32>) -> i32 {
//         let mut store: HashMap<i32, i32> = HashMap::new();
//         let mut res = -1;

//         for i in 0..nums.len() {
//             if store.contains_key(&nums[i]) {
//                 res = nums[i];
//                 break;
//             }
//             else {
//                 store.insert(nums[i], 0);
//             }
//         }

//         res
//     }
// }

// 交换法
impl Solution {
    pub fn find_repeat_number(mut nums: Vec<i32>) -> i32 {
        let mut res = -1;
        if nums.len() == 1 {
            return -1;
        }

        for i in 0..nums.len() {
            let index = nums[i] as usize;
            if nums[i] == nums[index] && i != index {
                res = nums[i];
                break;
            }
            else {
                let t = nums[i];
                nums[i] = nums[index];
                nums[index] = t;
            }
        }

        res
    }
}
```
