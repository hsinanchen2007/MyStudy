go程序员已经快乐的下班.
cpp程序员还在打断点.
rust程序员还在编译.

上次编译就剩一个错误了， 修改下, duang！

 
```
error: aborting due to 9 previous errors
```

```
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

/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。


示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.

 */
struct Solution{}

impl Solution {
    pub fn swap_pairs(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy_head = ListNode::new(0);
        let mut prev = &mut dummy_head.next;
        let mut head = head;
        while let Some(mut cur) = head.take() {
            if let Some(mut next) = cur.next.take() {
                head = next.next.replace(cur);
                prev.replace(next);   
                prev = &mut prev.as_mut().unwrap().next.as_mut().unwrap().next;
            } else {
                prev.replace(cur);
            }
         }

        dummy_head.next
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

    println!("{:?}",  Solution::swap_pairs(init_nodes(5)));
}

```
