Rust 使用快排方式找到元素

```rust
impl Solution {
  	fn par(nums: &mut [i32], k: i32) -> i32 {
		let p = nums[0];
		let mut p_i = 0;
		for i in 1..nums.len() {
			if nums[i] < p {
				if p_i + 1 >= i {
					nums.swap(p_i, i);
				} else {
					nums.swap(p_i, p_i + 1);
					nums.swap(p_i, i);
				}
				p_i += 1;
			}
		}
		let length = nums.len();
		if k as usize == p_i {
			nums[p_i]
		} else if (k as usize) < p_i {
			Self::par(&mut nums[0..p_i], k)
		} else {
			Self::par(&mut nums[(p_i + 1)..length], k - p_i as i32 - 1)
		}
	}

	pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
		let mut nums = nums;
		let k = (nums.len() - k as usize) as i32;
		Self::par(&mut nums[..], k)
	}
}
```
