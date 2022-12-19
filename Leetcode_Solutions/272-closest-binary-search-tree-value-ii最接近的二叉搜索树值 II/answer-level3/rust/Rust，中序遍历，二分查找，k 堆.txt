- 中序遍历获得有序值数组 O(n)
- 二分查找寻找最接近的值（某个方向上的）O(logn)
- 向两侧分别查找 k 个，在 2k 个值中寻找最接近的 k 个值 O(K*logK)

![图片.png](https://pic.leetcode-cn.com/027853e02eea1d918026c2b3f28ab283900682f1cff4aa6d29442388e2c87fd8-%E5%9B%BE%E7%89%87.png)


```rust
use std::cell::RefCell;
use std::cmp::Ordering;
use std::collections::BinaryHeap;
use std::rc::Rc;

enum NodeOrVal {
    Node(Option<Rc<RefCell<TreeNode>>>),
    Val(i32),
}

#[derive(PartialEq, PartialOrd)]
struct NonNan(f64);

impl Eq for NonNan {}

impl Ord for NonNan {
    fn cmp(&self, other: &Self) -> Ordering {
        self.partial_cmp(other).unwrap()
    }
}

impl Solution {
    pub fn closest_k_values(root: Option<Rc<RefCell<TreeNode>>>, target: f64, k: i32) -> Vec<i32> {
        let sorted = Solution::inorder_traversal(root);
        Solution::find_closest(&sorted, target, k as isize)
    }

    pub fn find_closest(arr: &[i32], target: f64, k: isize) -> Vec<i32> {
        if (arr.len() as isize) <= k {
            return arr.iter().cloned().collect();
        }
        let mut begin = 0isize;
        let mut end = arr.len() as isize;
        let mut heap = BinaryHeap::<(NonNan, i32)>::new();
        while begin + 1 < end {
            let mid = (begin + end) / 2;
            let mid_val = f64::from(arr[mid as usize] as i32);
            if mid_val <= target {
                begin = mid;
            } else {
                end = mid;
            }
        }
        let mut i = begin;
        while i >= 0 && i >= begin - k {
            let sub 
                = (NonNan(f64::abs(arr[i as usize] as f64 - target)), arr[i as usize]);
            Solution::cmp_add(&mut heap, sub, k);
            i-=1;
        }
        i = begin + 1;
        while i < (arr.len() as isize) && i <= begin + k {
            let sub 
                = (NonNan(f64::abs(arr[i as usize] as f64 - target)), arr[i as usize]);
            Solution::cmp_add(&mut heap, sub, k);
            i+=1;
        }
        heap.iter().map(|(_, v)| *v).collect()
    }

    pub fn cmp_add(heap: &mut BinaryHeap<(NonNan, i32)>, elem: (NonNan, i32), k: isize) {
        if heap.len() < k as usize {
            heap.push(elem);
        } else {
            let top = heap.pop().unwrap();
            if top.0 < elem.0 {
                heap.push(top);
            } else {
                heap.push(elem);
            }
        }
    }

    pub fn inorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        use NodeOrVal::{Node, Val};
        let mut values = vec![];
        let mut stack: Vec<NodeOrVal> = vec![Node(root)];
        while let Some(node_or_val) = stack.pop() {
            match node_or_val {
                Node(node) => {
                    if let Some(node_ref) = node {
                        let node_b = node_ref.borrow();
                        stack.push(Node(node_b.right.clone()));
                        stack.push(Val(node_b.val));
                        stack.push(Node(node_b.left.clone()));
                    }
                }
                Val(val) => {
                    values.push(val);
                }
            }
        }
        values
    }
}
```