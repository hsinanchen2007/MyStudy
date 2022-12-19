使用as_ref()可以得到引用的Option后，再unwrap()就不会发生数据被move的问题；
当然在unwrap之前去用clone()方法也可以（`node.clone().unwrap()`），但是会创建一个临时变量？
```
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    fn dfs(node: Option<Rc<RefCell<TreeNode>>>, depth: usize, nodes: &mut Vec<Vec<i32>>) {
        if node.is_none() {
            return
        }
        while nodes.len() <= depth {
            nodes.push(vec![]);
        }
        let val = node.as_ref().unwrap().borrow().val;
        nodes[depth].push(val);
        Self::dfs(node.as_ref().and_then(|nd| nd.borrow().left.clone()), depth+1, nodes);
        Self::dfs(node.as_ref().and_then(|nd| nd.borrow().right.clone()), depth+1, nodes);
    }
    pub fn level_order_bottom(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut res = vec![];
        Self::dfs(root,0,&mut res);
        res.reverse();
        res
    }
}
```