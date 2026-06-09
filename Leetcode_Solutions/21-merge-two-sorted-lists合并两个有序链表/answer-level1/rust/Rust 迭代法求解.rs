```
impl Solution {
    pub fn merge_two_lists(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if let None = l1 {
            return l2;
        }else if let None = l2 {
            return l1
        };
        //取node的val
        let node_val = |x: &Option<Box<ListNode>>| if let Some(node) = x {
            Some(node.val)
        }else {
            None
        };
        //保证l1的第一个node<=l2的第一个node
        let res = if node_val(&l1).unwrap() <= node_val(&l2).unwrap() {
            Solution::merge(l1, l2)
        }else {
            Solution::merge(l2, l1)
        };

        res
    }

    pub fn merge(mut l1: Option<Box<ListNode>>, mut l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        //取node的val
        let node_val = |x: &Option<Box<ListNode>>| if let Some(node) = x {
            Some(node.val)
        }else {
            None
        };
        //取node.next的val
        let node_next_val = |x: &Option<Box<ListNode>>| if let Some(node) = x {
            if let Some(node_next) = &node.next {
                Some(node_next.val)
            }else {
                None
            }
        }else {
            None
        };

        let mut p = &mut l1;        
        loop {
            //l2遍历结束，合并完成
            if let None = node_val(&l2) {
                break;
            }
            //l1遍历结束，将l2剩余的部分直接接在l1后面
            if let None = node_next_val(p) {
                if let Some(node) = p {
                    node.next = l2;
                }
                break;
            }
            //当l2的当前node的val位于l1当前node和下一node的val之间时，插入节点；p指针右移
            if node_val(p).unwrap() <= node_val(&l2).unwrap() && node_next_val(p).unwrap() > node_val(&l2).unwrap() {
                if let Some(node) = p {
                    let t1 = node.next.clone();
                    node.next = Some(Box::new(ListNode::new(node_val(&l2).unwrap())));
                    if let Some(node_next) = &mut node.next {
                        node_next.next = t1;
                    }
                    p = &mut node.next;
                }
                l2 = match l2 {
                    Some(node) => node.next,
                    None => None,
                };
            }else {
                if let Some(node) = p {
                    p = &mut node.next;
                }
            }
        }

        l1
    }
}
```
![image.png](https://pic.leetcode-cn.com/bee68523ae5eb20b8d14d50cb72932f7b381f584dd1e76eaa27ec95f4c1177ca-image.png)
