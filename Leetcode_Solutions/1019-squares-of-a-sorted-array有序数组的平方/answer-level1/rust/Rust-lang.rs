### 运行结果
![image.png](https://pic.leetcode-cn.com/d7dc13ebe56b2b251832705ca388c5af99c8db148c2941758953121a6e8ff1c6-image.png)


### 解题思路
见代码

### 代码

```rust
impl Solution {
    pub fn sorted_squares(a: Vec<i32>) -> Vec<i32> {
        let mut ans: Vec<i32> = a;
        
        for item in &mut ans {
            *item = item.pow(2); // 平方
        }
        ans.sort(); // 排序

        (ans)
    }
}
```