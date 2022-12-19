```rust
impl Solution {
    /// ```
    /// use leetcode::Solution;
    /// use leetcode::ListNode;
    /// 
    /// let l1 = Some(Box::new(ListNode::from_vec(&vec![2, 4, 3])));
    /// let l2 = Some(Box::new(ListNode::from_vec(&vec![5, 6, 4])));
    /// let expected = Some(Box::new(ListNode::from_vec(&vec![7, 0, 8])));
    /// assert_eq!(Solution::add_two_numbers(l1, l2), expected);
    /// ```
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut dummy = Box::new(ListNode::new(0));
        let mut curr = &mut dummy;

        let (mut c1, mut c2) = (&l1, &l2);

        let mut carry = 0;

        while c1.is_some() || c2.is_some() || carry != 0 {
            let mut digit = carry;
            if let Some(node) = &c1 {
                digit += (*node).val;
                c1 = &(*node).next;
            }
            if let Some(node) = &c2 {
                digit += (*node).val;
                c2 = &(*node).next;
            }

            carry = digit / 10;
            digit %= 10;

            curr.next = Some(Box::new(ListNode::new(digit)));
            curr = curr.next.as_mut().unwrap();
        }

        (*dummy).next
    }
}
```