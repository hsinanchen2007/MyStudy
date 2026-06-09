# 优先队列 4ms 3.2MB
```rust
use std::collections::BinaryHeap;
impl PartialOrd for ListNode {
    fn partial_cmp(&self, other: &ListNode) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}
impl Ord for ListNode {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        other.val.cmp(&self.val)
    }
}
pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
    if lists.is_empty() { return None }
    let mut heap = BinaryHeap::with_capacity(lists.len());
    for l in lists {
        if let Some(l) = l {
            heap.push(l);
        }
    }

    let mut dummy = ListNode::new(0);
    let mut p  = &mut dummy;
    while !heap.is_empty() {
        let mut min_l = heap.pop().unwrap();
        if heap.is_empty() {
            p.next = Some(min_l);
            break;
        }
        let next = min_l.next.take();
        if next.is_some() {
            heap.push(next.unwrap());
        }
        p.next = Some(min_l);
        p = p.next.as_deref_mut().unwrap();
    }
    dummy.next
}
```
# 分治 4ms 3.1MB
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
pub fn merge_k_lists(mut lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
    let mut len = lists.len();
    if len == 0 { return None }
    while len > 1 {
        for i in 0..len / 2 {
            lists[i] = merge_two_lists(lists[i].take(), lists[len - i - 1].take());
        }
        len = (len + 1) / 2;
    }
    lists[0].take()
}
```
# 逐一比较 56ms 3MB
```rust
pub fn merge_k_lists(mut lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
    if lists.is_empty() { return None }
    let mut dummy = ListNode::new(0);
    let mut p  = &mut dummy;
    while !lists.is_empty() {
        let mut min_i = None;
        let mut min_val = i32::max_value();
        let mut i = 0;
        while i < lists.len() {
            let l = &mut lists[i];
            let cur_p = if let Some(p) = l.as_mut() { p } else {
                lists.swap_remove(i);
                continue
            }; 
            let val = cur_p.val;
            if val <= min_val {
                min_val = val;
                min_i = Some(i);
            }
            i += 1;
        }
        if lists.len() == 1 {
            p.next = lists.remove(0);
            break;
        }
        let (i, max_p) = if let Some(i) = min_i { (i, lists[i].as_mut().unwrap()) } else { break };
        let next = max_p.next.take();
        p.next = if next.is_some() {
            std::mem::replace(&mut lists[i], next)
        } else {
            lists.swap_remove(i)
        };
        p = p.next.as_deref_mut().unwrap();
    }
    dummy.next
}
```
