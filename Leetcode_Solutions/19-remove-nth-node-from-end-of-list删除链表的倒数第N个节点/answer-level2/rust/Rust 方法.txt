// 执行用时 :
// 0 ms, 在所有 Rust 提交中击败了100.00%的用户
// 内存消耗 :
// 1.9 MB, 在所有 Rust 提交中击败了100.00%的用户
impl Solution {
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        let mut head_ans: Option<Box<ListNode>> = None;
        let mut p1 = &head;
        let mut p2 = &head;
        let mut p_head_ans = &mut head_ans;
        for _ in 0..n{
            if let Some(node_p2) = p2{
                p2 = &node_p2.next;
            }
        }
        while let Some(_) = p2{
            if let Some(node_p1) = p1{
                *p_head_ans = Some(Box::new(
                                        ListNode::new(
                                            node_p1.val)));
                if let Some(node_ans) = p_head_ans{
                    p_head_ans = &mut node_ans.next;
                }
            }

            if let Some(node_p1) = p1{
                p1 = &node_p1.next;
            }
            if let Some(node_p2) = p2{
                p2 = &node_p2.next;
            }
        }

        if let Some(node_p1) = p1{
            p2 = &node_p1.next;
        }
        while let Some(node_p2) = p2{
            *p_head_ans = Some(Box::new(
                                    ListNode::new(
                                        node_p2.val)));
            if let Some(node_ans) = p_head_ans{
                p_head_ans = &mut node_ans.next;
            }
            
            if let Some(node_p2) = p2{
                p2 = &node_p2.next;
            }
        }

        head_ans
    }
}