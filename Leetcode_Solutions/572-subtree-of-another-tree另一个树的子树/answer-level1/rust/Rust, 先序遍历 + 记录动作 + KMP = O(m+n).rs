看官方解答，最优解是O(mn)，感觉自己这个应该是O(m+n)，更优，如果有错误希望大佬指出。

简而言之： 

1. 先序遍历树 A。注意，单纯先序打印内容不行，不能唯一确定一棵树，要记录所有动作 -- 如左下、左下、打印 1 、右上、打印2、右下...O(m)
2. 先序遍历树 B，记录所以动作...O(n)
3. 将A、B遍历记录的动作转换成字符串
4. 运用`KMP算法`匹配 `B_str.contains(A_str)`

详细代码如下，包括单元测试，时空均超过 100%：

```rust
// @lc code=start
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn is_subtree(s: Option<Rc<RefCell<TreeNode>>>, t: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let s_actions = Rc::new(RefCell::new(vec![]));
        Solution::log_traverse_actions(&s, s_actions.clone()); // O(m)
        let t_actions = Rc::new(RefCell::new(vec![]));
        Solution::log_traverse_actions(&t, t_actions.clone()); // O(n)
        let s_actions = s_actions.borrow().join(",");
        let t_actions = t_actions.borrow().join(",");
        s_actions.contains(&t_actions) // kmp O(m + n)
    }

    fn log_traverse_actions(r: &Option<Rc<RefCell<TreeNode>>>,actions: Rc<RefCell<Vec<String>>>) {
        match r {
            None => actions.borrow_mut().push("n".to_string()),
            Some(node_ref) => {
                let node_borrow = node_ref.borrow();
                {
                    let mut actions_mut = actions.borrow_mut();
                    actions_mut.push("a".to_string());
                }
                Solution::log_traverse_actions(&node_borrow.left, actions.clone());
                {
                    let mut actions_mut = actions.borrow_mut();
                    actions_mut.push("b".to_string());
                    actions_mut.push(node_borrow.val.to_string());
                    actions_mut.push("c".to_string());
                }
                Solution::log_traverse_actions(&node_borrow.right, actions.clone());
                {
                    let mut actions_mut = actions.borrow_mut();
                    actions_mut.push("c".to_string());
                }
            }
        }
    }
}
// @lc code=end

use crate::utils::tree::TreeNode;
struct Solution;

#[cfg(test)]
mod test {
    use super::*;
    use crate::{tree_node,tree_leaf};

    #[test]
    fn test_is_subtree1() {
        let tree1 = tree_node!(
            3,
            tree_node!(4, tree_leaf!(1), tree_leaf!(2)),
            tree_leaf!(5)
        );
        let tree2 = tree_node!(
            4,tree_leaf!(1), tree_leaf!(2)
        );
        assert!(Solution::is_subtree(tree1, tree2));
    }

    
    #[test]
    fn test_is_subtree2() {
        let tree1 = tree_node!(
            3,
            tree_node!(4, tree_leaf!(1), tree_node!(2, tree_leaf!(0), None)),
            tree_leaf!(5)
        );
        let tree2 = tree_node!(
            4,tree_leaf!(1), tree_leaf!(2)
        );
        assert!(!Solution::is_subtree(tree1, tree2));
    }
}
```