impl Solution {
    pub fn get_decimal_value(head: Option<Box<ListNode>>) -> i32 {
        let mut sum = 0;
        let mut p = &head;
        while let Some(node) = p {
            sum = sum << 1;
            sum |= node.val;
            p = &node.next;
        };
        sum
    }
}