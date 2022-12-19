尽量写得很清晰，给大家参考一下
```rust
pub fn four_sum(mut nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
    let mut res = Vec::new();
    let len = nums.len();
    if len < 4 { return res }
    nums.sort_unstable(); // 此处使用新 API sort_unstable 达到更高效率，没有额外内存分配

    let min = nums[0] + nums[1] + nums[2] + nums[3];
    if target < min { return res }
    let max = nums[len - 1] + nums[len - 2] + nums[len - 3] + nums[len - 4];
    if target > max { return res }

    for i in 0..len - 3 {
        let a = nums[i];
        if i != 0 && nums[i - 1] == a { continue }

        let min = a + nums[i + 1] + nums[i + 2] + nums[i + 3];
        if target < min { break }
        let max = a + nums[len - 1] + nums[len - 2] + nums[len - 3];
        if target > max { continue }

        for j in i + 1..len - 2 {
            let b = nums[j];
            if j != i + 1 && nums[j - 1] == b { continue }
            let (mut l, mut r) = (j + 1, len - 1);

            let min = a + b + nums[l] + nums[l + 1];
            if target < min { break } // 看见很多人这句写的是 continue，逻辑上应为 break
            let max = a + b + nums[r] + nums[r - 1];
            if target > max { continue }

            while l < r {
                let (c, d) = (nums[l], nums[r]);
                let sum = a + b + c + d;
                let diff = sum - target;
                if diff == 0 {
                    res.push(vec![a, b, c, d]);
                    while l < r && nums[l] == nums[l + 1] { l += 1 }
                    while l < r && nums[r] == nums[r - 1] { r -= 1 }
                    l += 1;
                    r -= 1;
                } else if diff > 0 {
                    r -= 1;
                } else {
                    l += 1;
                }
            }
        }
    }
    res
}
```