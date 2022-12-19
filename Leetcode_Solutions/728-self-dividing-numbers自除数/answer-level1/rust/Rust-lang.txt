### 运行结果

![image.png](https://pic.leetcode-cn.com/c5bb887d34751f41e2bbf09432d6cad39c14f97ef83c898919eea098fa08ac4a-image.png)

### 代码

```rust
impl Solution {
    pub fn self_dividing_numbers(left: i32, right: i32) -> Vec<i32> {
        let mut ans: Vec<i32> = vec![];

        for i in left..(right + 1) {
            ans.push(i);
            let mut x = i;
            while 0 != x { // 判断是否自然数
                let tmp = x % 10;
                if 0 != tmp && 0 == (i % tmp) {
                    x /= 10;
                } else {
                    ans.pop();
                    break;
                }
            }
        }

        (ans)
    }
}
```

### 算法复杂度

**空间复杂度：O(n)**

**时间复杂度：O(n * b)**，b为 (left + right) / 2 的位数