```rust
pub fn swap_pairs(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    if head.is_none() { return head }
    let mut b: *mut _ = &mut head;
    loop { unsafe {
        let a = b;
        b = if let Some(b) = (*b).as_mut() {
            &mut b.next
        } else { break };
        let c = if let Some(b) = (*b).as_mut() {
            &mut b.next
        } else { break };
        std::ptr::swap(a, b);
        std::ptr::swap(b, c);
    }}
    head
}
```
