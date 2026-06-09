### 解题思路
![image.png](https://pic.leetcode-cn.com/1ef4fe073862096d4983e9883b5cb9f8679711046c5321a2250b9c21e4d17eaa-image.png)


### 代码

```rust
impl Solution {
    pub fn find_special_integer(arr: Vec<i32>) -> i32 {
        let t = arr.len() / 4;
        for i in 0..arr.len() - 1 {
            if arr[i] == arr[i + t] {
                return arr[i];
            }
        }
        arr[0]
    }
}
```