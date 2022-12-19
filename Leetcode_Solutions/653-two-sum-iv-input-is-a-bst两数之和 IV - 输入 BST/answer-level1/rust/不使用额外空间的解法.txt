0ms，不使用额外空间，利用bst的性质。

先序遍历这颗bst，每遇到一个节点v，计算t=k-v。如果t小于等于v，那么就在当前节点的左子树中进行查找，否则从根开始查找t。最坏复杂度是nlogn

```rust
impl Solution {
    pub fn find_target(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> bool {
        let mut ans =false;
        Self::visit(&root, &root, k, &mut ans);
        ans
    }
    fn visit(cur: &Option<Rc<RefCell<TreeNode>>>, root: &Option<Rc<RefCell<TreeNode>>>, k: i32, ans: &mut bool ) {
        if cur.is_none() {
            return;
        }
        if *ans {
            return;
        }
        let br = cur.as_ref().unwrap().borrow();
        let rest = k-br.val;
        if rest <= br.val {
            if Self::search(&br.left, rest) {
                *ans = true;
            }
        } else {
            if Self::search(root, rest) {
                *ans = true;
            }
        }
        if *ans {
            return;
        }
        Self::visit(&br.left, root, k, ans);
        Self::visit(&br.right, root, k, ans);
    }
    fn search(root: &Option<Rc<RefCell<TreeNode>>>, k: i32) -> bool {
        if root.is_none() {
            return false;
        }
        let br = root.as_ref().unwrap().borrow();
        if br.val == k {
            return true;
        }
        if k < br.val {
            Self::search(&br.left, k)
        }  else {
            Self::search(&br.right, k)
        }
    }
}
```