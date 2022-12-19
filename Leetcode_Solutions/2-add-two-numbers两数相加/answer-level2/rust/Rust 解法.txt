```
impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut cf = 0;
        let node_val = |x: &Option<Box<ListNode>>| {
            if let Some(node) = x {
                Some(node.val)
            }else {
                None
            }
        };
        let mut res: Option<Box<ListNode>> = None;
        let (mut p1, mut p2, mut pr) = (&l1, &l2, &mut res);

        loop {            
            let mut sum = 0;
            match (node_val(p1), node_val(p2)) {
                (Some(val1), Some(val2)) => {
                    sum = val1 + val2 + cf;                    
                },
                (Some(val1), None) => {
                    sum = val1 + cf;                    
                },
                (None, Some(val2)) => {
                    sum = val2 + cf;
                },
                (None, None) => {
                    if cf == 1 {
                        *pr = Some(Box::new(ListNode::new(1)));
                    }    
                    break;
                },
            };

            cf = sum / 10;
            sum = sum - 10 * cf;
            *pr = Some(Box::new(ListNode::new(sum)));
            // println!("p1: {:?}, p2: {:?}, pr: {:?}, sum: {}", node_val(p1), node_val(p2), node_val(pr), sum);
            // p1 = &p1.as_ref().unwrap().next; 另一种写法，要求p1不为None；
            if let Some(node) = p1 {
                p1 = &node.next;
            }
            if let Some(node) = p2 {
                p2 = &node.next;
            }
            if let Some(node) = pr {
                pr = &mut node.next;
            }
        }
        
        res
    }
}
```
![image.png](https://pic.leetcode-cn.com/21099a34128d27462929c27a60c97d4f70da9347769fc8c672dad876784138ea-image.png)
