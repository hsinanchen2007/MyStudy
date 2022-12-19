### 解题思路
Rust 0ms answer

### 代码

```rust
impl Solution {
pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
    let (nums1_len,nums2_len) = (nums1.len(),nums2.len());
    let (mid,mid1) = ((nums1_len + nums2_len)>>1,(nums1_len + nums2_len-1) >> 1);
    let (mut a, mut b,mut nums1_index,mut nums2_index) = (0,0,0,0);
    for _ in 0..(mid+1) {
        b = a;
        if nums2_index >= nums2_len || (nums1_index < nums1_len && nums1[nums1_index] < nums2[nums2_index]) {
            a = nums1[nums1_index];
            nums1_index += 1;
            continue;
        }
        a = nums2[nums2_index];
        nums2_index += 1;
    }
    if mid == mid1 {
        a as f64
    }else{
        (a + b) as f64 / 2.0
    }
}
}
```