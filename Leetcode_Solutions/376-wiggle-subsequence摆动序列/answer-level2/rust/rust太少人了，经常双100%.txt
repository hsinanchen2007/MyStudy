其实很容易看出来，`nums[i] - nums[i-1]`的符号是`正`的或者`负`，是下一个状态转移的关键。

将官方题解的up和down，应该理解为，两种状态。

如果我们只有一个dp，因为起始的符号不同，每个dp[i]都有不一样的状态转移条件，写起来比较麻烦。

分开两个dp，在特定的情况下，状态转移条件很固定。


```rust
impl Solution {
  pub fn wiggle_max_length(nums: Vec<i32>) -> i32 {
    let len = nums.len();
    if len < 2 {
      return len as i32;
    }

    let mut down = 1;
    let mut up = 1;

    for i in 1..len {
      if nums[i] > nums[i - 1] {
        up = std::cmp::max(down + 1, up);
      } else if nums[i] < nums[i - 1] {
        down = std::cmp::max(up + 1, down);
      }
    }

    std::cmp::max(down, up)
  }
```


如果只有一个dp，就是下面这张，判断条件复杂很多，要记住前一个导致增加的符号是什么，跟当前的符号做对比。

```rust

impl Solution {
  pub fn wiggle_max_length(nums: Vec<i32>) -> i32 {
    let len = nums.len();
    if len < 2 {
      return len as i32;
    }

    let mut wml = 1;
    let mut prev = false;
    for i in 1..len {
      if nums[i] == nums[i - 1] {
        continue;
      }

      let now = nums[i] > nums[i - 1];

      if i == 1 {
        prev = now;
        wml += 1;
        continue;
      }

      if now != prev {
        prev = now;
        wml += 1;
      }
    }
    wml
  }
}

```