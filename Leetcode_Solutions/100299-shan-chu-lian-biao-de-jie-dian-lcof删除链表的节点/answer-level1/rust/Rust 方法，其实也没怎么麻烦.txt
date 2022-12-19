```
impl Solution {
    pub fn delete_node(head: Option<Box<ListNode>>, val: i32) -> Option<Box<ListNode>> {
        let mut head = Some(Box::new(ListNode {
            next: head,
            val: 0
        }));
        let mut p = &mut head;

        while p.as_ref().unwrap().next != None {
            if p.as_ref().unwrap().next.as_ref().unwrap().val == val {
                p.as_mut().unwrap().next = p.as_mut().unwrap().next.take().unwrap().next;
                break;
            }
            p = &mut p.as_mut().unwrap().next;
        }

        head.unwrap().next
    }
}
```
