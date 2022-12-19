### 运行结果

![image.png](https://pic.leetcode-cn.com/270172c437f6a396906a6433c7c2da37f4f0177886b8f27efae4a49397033779-image.png)

### 解题思路
双端队列实现，应该是效率最低的方法了吧

### 代码

```rust
use std::collections::VecDeque;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut queue: VecDeque<u8> = VecDeque::new();
        let mut count: Vec<i32> = Vec::new();

        for item in s.bytes() {
            if queue.contains(&item) {
                let len = queue.len();
                count.push(len as i32);
                while queue.contains(&item) {
                    queue.pop_front();
                }
            }
            queue.push_back(item);
        }
        let len = queue.len();
        count.push(len as i32);

        (*count.iter().max().unwrap())
    }
}
```