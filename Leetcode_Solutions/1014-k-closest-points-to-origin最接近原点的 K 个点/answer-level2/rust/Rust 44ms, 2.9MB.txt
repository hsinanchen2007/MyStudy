### 解题思路
![图片.png](https://pic.leetcode-cn.com/49769c074f14e4c39352ab30020da2c62bf758780aa0a7ec6d9ff3cb16c32b02-%E5%9B%BE%E7%89%87.png)

### 代码

```rust
impl Solution {
    pub fn k_closest(points: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let mut points = points;
        points.sort_by_key(|p| p[0] * p[0] + p[1] * p[1]);
        let mut closest_k = Vec::new();
        for i in 0..k as usize {
            closest_k.push(points[i].clone());
        }
        closest_k
    }
}

```