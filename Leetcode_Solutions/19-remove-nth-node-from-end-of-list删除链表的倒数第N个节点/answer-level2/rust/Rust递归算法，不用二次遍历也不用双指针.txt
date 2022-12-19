```rust
impl Solution {
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        Solution::remove(head, n).0
    }

    fn remove(head: Option<Box<ListNode>>, n: i32) -> (Option<Box<ListNode>>, i32) {
        if let Some(node) = head {
            let (removed, cnt) = Solution::remove(node.next, n);
            if cnt + 1 == n {
                (removed, cnt + 1)
            } else {
                let mut new_node = Box::new(ListNode::new(node.val));
                new_node.next = removed;
                (Some(new_node), cnt + 1)
            }
        } else {
            (None, 0)
        }
    }
}
```
