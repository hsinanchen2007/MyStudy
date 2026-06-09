### 解题思路
简单替换next指向的位置即可。用图画画出来步骤会更清晰。

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
impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut cur = head;
        let mut last = None;
        loop {
            if let Some(mut node) = cur {
                cur = (*node).next;
                (*node).next = last;
                last = Some(node);
            } else {
                return last;
            }
        }
        panic!();
    }
}
```