用rust练习语法，已经遇到2-3道链表题了，感觉很不舒服，吐了就舒服了！

```
struct Solution{}

// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>
}
 
impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode {
        next: None,
        val
        }
    }
}
impl Solution {
    pub fn merge_two_lists(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy_head = Some(Box::new(ListNode::new(0)));
        let mut prev = &mut dummy_head;
        let mut l1 = l1;
        let mut l2 = l2;
 
        while l1.is_some() && l2.is_some() {
            let v1 = l1.as_ref().unwrap().val;
            let v2 = l2.as_ref().unwrap().val;
            if v1 < v2 {
                prev.as_mut().unwrap().next = l1;
                l1 = prev.as_mut().unwrap().next.as_mut().unwrap().next.take();  // 优雅啊！
            } else {
                prev.as_mut().unwrap().next = l2;
                l2 = prev.as_mut().unwrap().next.as_mut().unwrap().next.take(); // 优雅的飞起!
            }
            prev = &mut prev.as_mut().unwrap().next; 
        }

        if l1.is_none() {
            prev.as_mut().unwrap().next = l2;
        } else {
            prev.as_mut().unwrap().next = l1;
        }
        return dummy_head.as_mut().unwrap().next.take();
    }
}
fn init_nodes(n: i32) -> Option<Box<ListNode>> {
    let mut head = Some(Box::new(ListNode::new(1)));
    let mut prev = &mut head;
    for v in 2..n+1 {
        match prev {
            Some(node) => {
                node.next = Some(Box::new(ListNode::new(v)));
                prev = &mut node.next;
            },
            None => {},
        }
    }
    return head;
}
fn main() {
    let l1 = init_nodes(3);
    let l2 = init_nodes(5);
    println!("{:?}",  Solution::merge_two_lists(l1, l2));
}

```
