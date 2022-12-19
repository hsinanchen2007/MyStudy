<!-- 执行用时 :
0 ms, 在所有 Rust 提交中击败了100.00%的用户
内存消耗 :2.4 MB, 在所有 Rust 提交中击败了36.00%的用户 -->
```
impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if(head==None){
            return None;
        }
        let mut node_p1: Option<Box<ListNode>> = None;
        let mut node_p2 = &head;
        while let Some(node) = node_p2{
            let mut node_t = Some(Box::new(ListNode::new(node.val)));
            if let Some(n) = &mut node_t{
                n.next = node_p1;
            }
            node_p1 = node_t;
            node_p2 = &node.next;
        }
        node_p1
    }
}
```

