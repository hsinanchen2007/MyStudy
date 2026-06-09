用match写模式匹配很方便，递归讨论各种情况就好了

还在学习Rust，从指针中取出TreeNode那里感觉写得很丑陋
但是我不知道别的方法，欢迎指点:)

```
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn is_same_tree(p: Option<Rc<RefCell<TreeNode>>>, q: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match (p,q) {
            (None, None) => true,
            (None, _) | (_,None) => false,
            (Some(pr),Some(qr)) => {
                let (pr,qr) = (pr.as_ref(), qr.as_ref()); // & RefCell
                let (pr,qr) = (pr.borrow(), qr.borrow()); // & TreeNode 
                if pr.val == qr.val {
                    Self::is_same_tree(pr.left.clone(),qr.left.clone()) && Self::is_same_tree(pr.right.clone(),qr.right.clone())
                }else{
                    false
                }
            }
        }
    }
}
```