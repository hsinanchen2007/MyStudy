```rust
impl Solution {
    pub fn swap_pairs(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        Solution::swap_rec(head)
    }

    pub fn swap_rec(mut ptr: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if ptr.is_some() && ptr.as_ref().unwrap().next.is_some() {
            let mut next = ptr.as_mut().unwrap().next.take();
            let nnext = next.as_mut().unwrap().next.take();
            ptr.as_mut().unwrap().next = Solution::swap_rec(nnext);
            next.as_mut().unwrap().next = ptr;
            next
        } else{
            ptr
        }
    }
}

```
