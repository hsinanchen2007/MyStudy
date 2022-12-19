### 解题思路

基本上就是先合并数组，然后用双指针法找中点。

### 代码

```rust

impl Solution {
  // 先合并数组，然后用双指针法
  pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
    // 合并数组
    let mut vec: Vec<i32> = Vec::new();
    let (mut i1, mut i2): (usize, usize) = (0, 0);
    loop {
      let n1 = nums1.get(i1);
      let n2 = nums2.get(i2);
      match (n1, n2) {
        (Some(v1), Some(v2)) => {
          if v1 < v2 {
            vec.push(*v1);
            i1 += 1
          } else {
            vec.push(*v2);
            i2 += 1
          }
        }
        (Some(v1), None) => {
          vec.push(*v1);
          i1 += 1;
        }
        (None, Some(v2)) => {
          vec.push(*v2);
          i2 += 1;
        }
        (None, None) => {
          break;
        }
      }
    }
    // 双指针
    let (mut i1, mut i2): (usize, usize) = (0, 0);
    loop {
      let n2 = vec.get(i2);
      if let None = n2 {
        if let None = vec.get(i2 - 1) {
          // 奇数长度（2k+1）：i2 = 2k+2, i1 = k+1，
          // 中位数选第 k 位
          return *vec.get(i1 - 1).unwrap() as f64;
        } else {
          // 偶数长度（2k）：i2 = 2k, i1=k
          // 中位数选第 2k / 2 -+ 1 = k-1, k 位
          return (vec.get(i1 - 1).unwrap() + vec.get(i1).unwrap()) as f64 / 2f64;
        }
      }
      i1 += 1;
      i2 += 2;
    }
  }
}

```