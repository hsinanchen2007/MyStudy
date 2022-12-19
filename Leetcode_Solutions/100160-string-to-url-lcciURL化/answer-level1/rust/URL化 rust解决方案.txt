### 解题思路
此处撰写解题思路
运用的模式匹配，当初值遍历字符串有个坑，就是后面的空格不会被去掉，需要用用枚举方法
内存消耗有点大，运行时间40ms
![image.png](https://pic.leetcode-cn.com/b0cea8f296bdb4338e252b46ba6a7fa7d52e181b6fe96bbbb8a15082ae20f574-image.png)

### 代码

```rust
impl Solution {
    pub fn replace_spaces(s: String, length: i32) -> String {
        let mut res: String = String::from("");
        for (index, v) in s.chars().enumerate(){
            if index as i32 == length {break}
            match v {
                ' ' => {res += "%20"},
                _ => {res += &(v.to_string())}
            }
        }
        res
    }
}
```