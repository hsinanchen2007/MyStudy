```
impl Solution {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        let mut lists = lists;
        let (len, mut interval) = (lists.len(), 1);

        if len == 0 {
            return None;
        }

        while interval < len {
            let mut i = 0;
            while i < len-interval {
                lists[i] = Self::merge_two_lists(lists[i].clone(), lists[i+interval].clone());
                i += interval*2;
            }
            interval *= 2;
        }
        
        lists[0].clone()
    }

    pub fn merge_two_lists(
        mut list1: Option<Box<ListNode>>, 
        mut list2: Option<Box<ListNode>>) 
        -> Option<Box<ListNode>> {
        // Assume that the first node of list1 is smaller than that in list2
        if let None = list1 {
            // println!("list1 is empty");
            return list2;
        }
        if let None = list2 {
            // println!("list2 is empty");
            return list1;
        }
        
        let mut p1 = &list1;
        let mut p2 = &list2;
        let mut ans: Option<Box<ListNode>> = None;
        let mut p_ans = &mut ans;

        loop {
            let mut lesser_val = 0;
            let mut lesser_index = 1;
            
            if let None = p1 {
                while let Some(node_p2) = p2 {
                    *p_ans = Some(Box::new(ListNode::new(node_p2.val)));
                    if let Some(node) = p_ans {
                        p_ans = &mut node.next;
                    }
                    p2 = &node_p2.next;
                }
                break;
            }else if let Some(node) = p1 {
                lesser_val = node.val;
            }

            if let None = p2 {
                while let Some(node_p1) = p1 {
                    *p_ans = Some(Box::new(ListNode::new(node_p1.val)));
                    if let Some(node) = p_ans {
                        p_ans = &mut node.next;
                    }
                    p1 = &node_p1.next;
                }
                break;
            }else if let Some(node) = p2 {
                if lesser_val > node.val {
                    lesser_val = node.val;
                    lesser_index = 2;
                }
            }            

            *p_ans = Some(Box::new(ListNode::new(lesser_val)));
            if let Some(node) = p_ans {
                p_ans = &mut node.next;
            }
            
            match lesser_index {
                1 => if let Some(node) = p1 {
                    p1 = &node.next;
                },
                2 => if let Some(node) = p2 {
                    p2 = &node.next;
                },
                _ => panic!("lesser_index error!"),
            }

            // println!("lesser val is {}, lesser index is {}", lesser_val, lesser_index);
        }

        ans
    }
}
```
![image.png](https://pic.leetcode-cn.com/15a8d0f297002da19d7102b4e54af698110577445283766fc2d23774be66f2ab-image.png)

合并两个链表的部分比较头疼，虽然在“21. 合并两个有序链表”中尝试的“迭代法”和“取链表头组合法”都是0ms通过，但放在这道题中，前者要比后者慢100倍之多。猜测是迭代法的实现存在大量的clone，拖慢了时间。若要在摆脱clone，转为调用指针的方法，那就要通过rc智能指针或者unsafe的裸指针，前者与所给的数据结构不匹配，后者打算之后进一步尝试。递归法和取链表头组合差不多时间。目前最快的还是自己构造优先队列的方法，能达到4ms