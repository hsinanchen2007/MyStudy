### 解题思路
由于 Rust 的所有权限制，使用快慢指针时应使用只读引用，最后再提取 `slow` 引用的内容拷贝，有效降低内存。

注意特别的情况是，当 `fast` 指针指向最后一个元素的时候，就应该停止遍历。

更好的内存优化方法是把 `slow` 改成可变引用，或提取所有权。

### 代码

```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
use std::rc::Weak;
impl Solution {
    pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut fast = &head;
        let mut slow = &head;

        while let Some(ref node) = *fast {
            fast = &node.next;
            if let Some(ref next) = fast {
                fast = &next.next;
            } else {
                break;
            }

            if let Some(ref s) = *slow {
                if s.next.is_some() {
                    slow = &s.next;
                }
            }
        }

        slow.clone()
    }
}
```