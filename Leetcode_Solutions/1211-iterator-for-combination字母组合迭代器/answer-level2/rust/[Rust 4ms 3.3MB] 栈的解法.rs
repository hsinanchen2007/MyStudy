### 解题思路

求全排列一般用递归的方法，题目要求改写成非递归的迭代器。这就要用栈了。

### 代码

```rust
use std::iter::FromIterator;

pub struct CombinationIterator {
    chars: Vec<u8>,
    index_stack: Vec<usize>,
    has_next: bool,
}

impl CombinationIterator {
    pub fn new(characters: String, combination_length: i32) -> Self {
        CombinationIterator {
            chars: characters.into_bytes(),
            index_stack: Vec::from_iter(0..combination_length as usize),
            has_next: true,
        }
    }

    pub fn has_next(&self) -> bool {
        self.has_next
    }

    pub fn next(&mut self) -> String {
        if self.has_next {
            let result: Vec<u8> = self
                .index_stack
                .iter()
                .map(|index| self.chars[*index])
                .collect();
            if next_indexes(&mut self.index_stack, self.chars.len() - 1).is_none() {
                self.has_next = false;
            }
            unsafe { String::from_utf8_unchecked(result) }
        } else {
            String::new()
        }
    }
}

/// 把栈转移到下一个状态
/// `max` 是当前栈顶的允许出现的最大值
/// 成功到达下一状态时，返回 `Some(上一层的元素)` ，否则返回 None
fn next_indexes(stack: &mut Vec<usize>, max: usize) -> Option<usize> {
    match stack.pop() {
        None => None,
        Some(prev) if prev < max => {
            stack.push(prev + 1);
            Some(prev + 1)
        }
        // 递归地更改下一层的状态
        _ => match next_indexes(stack, max - 1) {
            Some(left) if left < max => {
                stack.push(left + 1);
                Some(left + 1)
            }
            _ => None,
        },
    }
}
```