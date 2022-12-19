```rust
pub fn remove_nth_from_end(mut head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
    let mut l: *const _ = &head;
    let mut d = head.as_mut().unwrap();
    let mut i = 0;
    while let Some(sl) = unsafe { &*l } {
        l = &sl.next;
        if i > n { d = d.next.as_mut().unwrap() }
        i += 1;
    }
    if i == n { return head.unwrap().next }
    d.next = d.next.take().unwrap().next;
    head
}
```
