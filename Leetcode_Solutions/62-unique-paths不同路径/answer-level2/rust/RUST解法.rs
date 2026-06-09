

首先按经典思路的二维数组思考，很简单，从左上角开始填表就是了。

```rust
impl Solution {
  pub fn unique_paths(m: i32, n: i32) -> i32 {
    let um = m as usize;
    let un = n as usize;
    let mut dp = vec![vec![0; un]; um];
    for i in 0..um {
      for j in 0..un {
        if i == 0 || j == 0 {
          dp[i][j] = 1;
          continue;
        }
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[um - 1][un - 1];
  }
}
```

然后做简化，变为一位数组。通过用表格模拟，发现只需要一维数组，就能保存上一行的后面部分和当前行的前面部分。

例如当前步是蓝色
![image.png](https://pic.leetcode-cn.com/001ed0a459d572ab5aa30f9eb0a75ea256b9a92632f00a0232c3d82241b7ea6f-image.png)

再执行一步就是这样
![image.png](https://pic.leetcode-cn.com/9672ec9cb4cace17d48e1bf8198fdb12e197476c81da2c6876b5ff42d714259e-image.png)

把黄色部分用一维数组保存就对了。

```rust
impl Solution {
  pub fn unique_paths(m: i32, n: i32) -> i32 {
    let um = m as usize;
    let un = n as usize;
    let mut dp = vec![0; un];
    for i in 0..um {
      for j in 0..un {
        if i == 0 || j == 0 {
          dp[j] = 1;
          continue;
        }
        dp[j] = dp[j - 1] + dp[j];
      }
    }
    return dp[un - 1];
  }
}
```



