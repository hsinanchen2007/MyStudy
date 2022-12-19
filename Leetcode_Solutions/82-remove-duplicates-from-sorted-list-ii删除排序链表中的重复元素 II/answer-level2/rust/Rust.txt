### 解题思路
前后指针，参考了@余栋 的写法
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
    pub fn delete_duplicates(p_head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if p_head.is_none() || p_head.as_ref().unwrap().next.is_none() {
            return p_head;
        }
        let mut head = Some(Box::new(ListNode{val:0, next:p_head}));
        let mut ptr = head.as_mut().unwrap();
        
        while ptr.next.is_some() {
            let mut curr_node = ptr.next.take();  //当前处理的节点
            let curr_value = curr_node.as_ref().unwrap().val;  //当前处理的节点的值
            let mut next = curr_node.as_mut().unwrap().next.take(); //当前处理的节点的下一个节点
            let mut flag = false; //是否重复的标志
            while next.is_some() {
                if next.as_ref().unwrap().val == curr_value {  //有重复节点
                    next = next.as_mut().unwrap().next.take();  //往前走
                    flag = true;
                } else {
                    break;
                }
            }
            if flag {
                ptr.next = next;   //跳过重复节点
                flag = false; //重置标志
            } else {
                ptr.next = curr_node; //把curr_node加回来
                ptr = ptr.next.as_mut().unwrap(); //指针往前走
                ptr.next = next; //把curr_node的next也加回来
            }
            
        }
        head.unwrap().next.take()
    }
}
```