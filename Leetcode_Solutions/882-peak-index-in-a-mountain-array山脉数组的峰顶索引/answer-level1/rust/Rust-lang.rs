### 运行结果

![image.png](https://pic.leetcode-cn.com/6dcf9655efbe8223a947bf6e4b5145418bf27bc2c1b577d14960165acc0b5e39-image.png)

### 解题思路
假设给出的序列为正确的“山峰”，遍历查找最大值，从前之后查找。不严谨，但过了，很迷。

### 代码

```rust
impl Solution {
        pub fn peak_index_in_mountain_array(a: Vec<i32>) -> i32 {
        let mut index = 0i32;
        let len = a.len();

        for i in 1..len {
            if a[i] > a[i - 1] {
                continue;
            } else {
                index = i as i32 - 1;
                break;
            }
        }

        (index)
    }
}
```