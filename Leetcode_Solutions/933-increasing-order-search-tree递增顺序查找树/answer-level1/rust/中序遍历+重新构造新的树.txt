### 解题思路
中序遍历得出数组，重新构造树。

### 代码

```rust
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn increasing_bst(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        fn inorder(root: Option<Rc<RefCell<TreeNode>>>,nums :&mut Vec<i32>){
            if let Some(root)=root {
                inorder(root.borrow().left.clone(), nums);
                nums.push(root.borrow().val);
                inorder(root.borrow().right.clone(),nums);
            }
        }
        let mut nums: Vec<i32>=Vec::new();
        inorder(root,&mut nums);
        let mut curr =Some(Rc::new(RefCell::new(TreeNode::new(0)))).clone();
        let mut head=curr.clone();
        // 重新构造树
        for i in nums{
            curr.as_ref().unwrap().borrow_mut().right=Some(Rc::new(RefCell::new(TreeNode::new(i))));
            curr=curr.clone().unwrap().borrow().right.clone();
        }
        head=head.clone().unwrap().borrow().right.clone();
        head
    }
}
```