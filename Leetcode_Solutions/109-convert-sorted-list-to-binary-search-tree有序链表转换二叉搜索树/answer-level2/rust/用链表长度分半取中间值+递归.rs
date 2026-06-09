先计算链表长度，然后除以2，取中间值作为root节点，两边递归运算作为left、right子树
众所周知，rust不用unsafe无法同时写出mut借用和ref借用，所以用长度代替快慢指针
```rust
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn sorted_list_to_bst(head: Option<Box<ListNode>>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut dummy_head = Some(Box::new(ListNode{val:0, next:head}));
        let mut ptr = dummy_head.as_mut().unwrap();
        let mut length = 0;
        while ptr.next.is_some() {
            length += 1;
            ptr = ptr.next.as_mut().unwrap();
        }
        ////println!("{}",length);
        Self::sorted_list_to_bst_rec(dummy_head.as_mut().unwrap().next.take(), length)
    }

    pub fn sorted_list_to_bst_rec(mut head: Option<Box<ListNode>>, length:usize) -> Option<Rc<RefCell<TreeNode>>> {
        if length == 0{
            return None;
        }
        if length == 1 {
            //println!("len=1, val={}", head.as_ref().unwrap().val);
            return Some(Rc::new(RefCell::new(TreeNode::new(head.as_ref().unwrap().val))));
        }
        let mut ptr = head.as_mut().unwrap();
        for _ in 0..length/2-1 {
            ptr = ptr.next.as_mut().unwrap();
        }
        ////println!("len={}, val={}",length, ptr.val);
        let right_half = ptr.next.take();
        let root = Some(Rc::new(RefCell::new(TreeNode::new(right_half.as_ref().unwrap().val))));
        root.as_ref().unwrap().borrow_mut().left = Self::sorted_list_to_bst_rec(head, length/2);
        root.as_ref().unwrap().borrow_mut().right = Self::sorted_list_to_bst_rec(right_half.unwrap().next, length-length/2-1);
        root
    }
}
```
