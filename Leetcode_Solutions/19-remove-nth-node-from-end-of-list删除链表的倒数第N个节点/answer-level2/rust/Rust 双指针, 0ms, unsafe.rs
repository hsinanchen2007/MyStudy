
```rust
type Link = Option<Box<ListNode>>;
impl Solution {

    pub fn remove_nth_from_end(mut head: Link, n: i32) -> Link {
        // 0ms, leet019
        let (mut p1, mut p2) = (&mut None as *mut Link, &head as *const Link);
        let mut cnt = 0;
        unsafe {
            while (*p2).is_some() {
                cnt += 1;
                p2 = &(*p2).as_ref().unwrap().next;
                if cnt > n {
                    p1 = &mut head; break;
                }
            }
            while (*p2).is_some() {
                p1 = &mut (*p1).as_mut().unwrap().next;
                p2 = &(*p2).as_ref().unwrap().next;
            }
            if (*p1).is_none() { head = head.unwrap().next;  }
            else {
                let mut node = (*p1).as_mut().unwrap();
                let mut next = node.next.take().unwrap();
                node.next = next.next;
            }
        }
        head
    }
}
```
