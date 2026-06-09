### 解题思路
![image.png](https://pic.leetcode-cn.com/5affea9775c0dfb1e6730599c886269c7ae7473af039f1db03f29a8197ffa56e-image.png)

通过递归和模式匹配，Rust的链表处理也可以很简洁清晰。注意到递归调用时需要使用 `Self::` 来引用当前结构体的函数。

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
    pub fn merge_two_lists(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        match (l1, l2) {
        (None, None) => None,
        (None, r) => r,
        (l, None) => l,
        (Some(mut l), Some(mut r)) => {
            if l.val <= r.val {
                l.next = Self::merge_two_lists(l.next, Some(r));
                Some(l)
            } else {
                r.next = Self::merge_two_lists(Some(l), r.next);
                Some(r)
            }
        }
    }
    }
}
```