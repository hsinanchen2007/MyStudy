0 ms; 2 MB
```rs
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn list_of_depth(tree: Option<Rc<RefCell<TreeNode>>>) -> Vec<Option<Box<ListNode>>> {
        let mut floor;
        match tree {
            None => {
                return vec![];
            },
            Some(_) => {
                floor = vec![tree];
            },
        }
        let mut r = vec![];
        while !floor.is_empty() {
            let mut floor1 = vec![];
            let mut list = vec![];
            for f in floor {
                if let Some(node) = f {
                    list.push(node.borrow().val);
                    floor1.push(node.borrow().left.clone());
                    floor1.push(node.borrow().right.clone());
                }
            }
            if !list.is_empty() {
                r.push(list.clone());
            }
            floor = floor1;
        }
        r.into_iter().map(|v| {
            v.into_iter().rev().fold(None, |acc, x| {
                let mut node = ListNode::new(x);
                node.next = acc;
                Some(Box::new(node))
            })
        }).collect()
    }
}
```