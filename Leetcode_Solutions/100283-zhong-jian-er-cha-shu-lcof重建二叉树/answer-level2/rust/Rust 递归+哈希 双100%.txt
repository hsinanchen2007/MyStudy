```
use std::rc::Rc;
use std::cell::RefCell;
use std::collections::HashMap;

impl Solution {
    pub fn build_tree(preorder: Vec<i32>, inorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        if preorder.len() == 0 { return None; }
        let mut map = HashMap::new();
        for (index, num) in inorder.iter().enumerate() {
            map.insert(*num, index);
        }
        Self::add_node(&preorder, &inorder, &map, 0, 0, preorder.len() as i32 -1)
    }

    pub fn add_node(preorder: &Vec<i32>, inorder: &Vec<i32>, map: &HashMap<i32, usize>, mut pre_root_index: usize, left: i32, right: i32) -> Option<Rc<RefCell<TreeNode>>> {
        if left > right { return None; }
        let cur = preorder[pre_root_index];
        let mut node = Some(Rc::new(RefCell::new(TreeNode::new(cur))));
        if left == right { return node; }

        let mut ino_root_index = map[&cur];
        node.as_mut().unwrap().borrow_mut().left = Self::add_node(
            preorder, inorder, map, pre_root_index+1, left, ino_root_index as i32 -1);
        node.as_mut().unwrap().borrow_mut().right = Self::add_node(
            preorder, inorder, map, pre_root_index+1+ino_root_index-left as usize, ino_root_index as i32+1, right);

        node
    }
}
```
