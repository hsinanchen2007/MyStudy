```rust
impl Solution {
pub fn reverse_list(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let mut prev = None;
    while head.is_some() {
        let mut node = head.unwrap();
        head = node.next;
        node.next = prev;
        prev = Some(node);
    }
    prev
}
}
```
