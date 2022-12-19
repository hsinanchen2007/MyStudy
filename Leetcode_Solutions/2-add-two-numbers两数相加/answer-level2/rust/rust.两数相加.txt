### 解题思路
此处撰写解题思路

### 代码

```rust
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
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut ans = Box::new(ListNode::new(0));
        let mut p_ans = &mut ans;

        let (mut p_l1, mut p_l2) = (&l1, &l2);

        let mut carry = 0;
        while p_l1.is_some() || p_l2.is_some(){
            let mut digit = carry;
            if let Some(node) = p_l1 {
                digit += node.val;
                p_l1 = &node.next;
            }
            if let Some(node) = p_l2 {
                digit += node.val;
                p_l2 = &node.next;
            }

             carry = digit / 10;
             digit %= 10;

             p_ans.next = Some(Box::new(ListNode::new(digit)));
             p_ans = p_ans.next.as_mut().unwrap();
        }
        if carry!=0{
            p_ans.next = Some(Box::new(ListNode::new(carry)));
        }
        ans.next
    }
    
}

```