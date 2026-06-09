### 运行结果

![image.png](https://pic.leetcode-cn.com/f3ac902a6415e7ed9a0787ec67226d078bff72b3731784c5f5125713a041dda7-image.png)

### 代码

```rust
impl Solution {
    pub fn replace_elements(arr: Vec<i32>) -> Vec<i32> {
        let mut ans = arr;
        let len = ans.len();
        let mut rmax = ans[len - 1];
        ans[len - 1] = -1;

        for i in 2..(len + 1) {
            let temp = ans[len - i]; // 从右向左遍历
            ans[len - i] = rmax;
            if temp > rmax {
                rmax = temp;
            }
        }

        (ans)
    }
}
```

### 算法复杂度

**空间复杂度：O(1)**

**时间复杂度：O(n)**