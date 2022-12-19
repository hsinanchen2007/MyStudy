```
impl Solution {
    pub fn three_sum_closest(mut nums: Vec<i32>, target: i32) -> i32 {
      nums.sort();
      let mut res = nums[0] + nums[1] + nums[2];
      for i in 0..(nums.len() - 2) {
        if i!=0 && nums[i] == nums[i - 1] {
          continue;
        }
        let (mut L, mut R) = (i + 1, nums.len() - 1);
        while L < R {
          let cur = nums[i] + nums[L] + nums[R];
          if (cur - target).abs() < (res - target).abs() {
            res = cur;
          }
          if cur > target {
            loop {
              R -= 1;
              if R <= L || nums[R] != nums[R + 1] {
                break;
              }
            }
          } else if cur < target {
            loop {
              L += 1;
              if L >= R || nums[L] != nums[L - 1] {
                break;
              }
            }
          } else {
            break;
          }
        }
      }
      res
    }
}
```
