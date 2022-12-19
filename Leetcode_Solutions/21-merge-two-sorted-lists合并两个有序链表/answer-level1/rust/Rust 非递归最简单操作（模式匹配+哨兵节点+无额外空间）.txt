```
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
    pub fn merge_two_lists(mut l1: Option<Box<ListNode>>, mut l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut head = Some(Box::new(ListNode::new(0)));
        let mut p = &mut head;

        loop {
            match (l1.as_mut(), l2.as_mut()) {
                (None, None) => { break; },
                (Some(node1), None) => {
                    p.as_mut().unwrap().next = l1.take();
                    break;
                },
                (None, Some(node2)) => {
                    p.as_mut().unwrap().next = l2.take();
                    break;
                },
                (Some(node1), Some(node2)) => {
                    if node1.val < node2.val {
                        let next = node1.next.take();
                        p.as_mut().unwrap().next = l1.take();
                        l1 = next;                    
                    }else  {
                        let next = node2.next.take();
                        p.as_mut().unwrap().next = l2.take();
                        l2 = next;
                    }
                    p = &mut p.as_mut().unwrap().next;
                },
            }
        }

        head.unwrap().next
    }
}
```
