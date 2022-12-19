因为链表不能从后往前数，可以利用递归的回溯阶段来数。
肯定不是最优解法，写着玩
```rust
impl Solution {
    pub fn travel(cur: &mut Box<ListNode>, n: i32) -> i32 {
        if let Some(child) = cur.next.as_mut() {
            let num = 1 + Self::travel(child, n);
            if num == n {
                cur.next = child.next.take();
            }
            return num;
        }
        return 0;
    }
    pub fn remove_nth_from_end(mut head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        let mut noop = ListNode::new(-1);
        noop.next = head;
        let mut noop = Box::new(noop);
        Self::travel(&mut noop, n);
        noop.next
    }
}
```
