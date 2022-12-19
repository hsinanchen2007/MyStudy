### 解题思路


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
         let mut sum = 0;
         let (mut l1, mut l2) = (l1, l2);
         let mut l = None;  // 在上下文中可以推断类型
         let mut p = &mut l;
  
         loop {                             
             match (l1, l2) {   // l1,l2是`move`语义匹配，每次匹配前都需要初始化值             
                 (Some(v1), Some(v2)) => {  
                     sum += v1.val + v2.val;
                     l1 = v1.next;
                     l2 = v2.next;
                 }
                 (Some(v1), None) => {
                     sum += v1.val;
                     l1 = v1.next;
                     l2 = None;      
                 }
                 (None, Some(v2)) => {
                     sum += v2.val;
                     l2 = v2.next;
                     l1 = None;
                 }
                 (None, None) => {
                      break;
                  }
             }
            *p = Some(Box::new(ListNode::new(sum % 10))); //不管sum是否大于10，都可以使用sum%10的值来构建新“节点“
             sum /= 10; // 获取进位值，否则初始为0
             if let Some(p_box_node) = p {
                 p = &mut p_box_node.next
             }
         }
             if sum != 0 {
             *p = Some(Box::new(ListNode::new(sum)));
             }
 
         l

    }
}
```
0ms,2.2m