```rust
pub fn merge_two_lists(mut l1: Option<Box<ListNode>>, mut l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let mut dummy = ListNode::new(0);
    let mut p = &mut dummy;
    while l1.is_some() && l2.is_some() {
        let (p1, p2) = (l1.as_deref_mut().unwrap(), l2.as_deref_mut().unwrap());
        if p1.val < p2.val {
            let next = p1.next.take();
            p.next = l1.take();
            l1 = next;
        } else {
            let next = p2.next.take();
            p.next = l2.take();
            l2 = next;
        }
        p = p.next.as_deref_mut().unwrap();
    }
    p.next = l1.or(l2);
    dummy.next
}
```