### 解题思路
思路没什么好说的，但是用Rust来实现对链表对操作真的让人头大。本来想在题解中抄个答案，都没找到Rust的实现，所以这里补一个。



### 代码
搞了半天，连编译都通不过，最后只能退而求其次用naive的解法来做：
```rust
impl Solution {
    pub fn odd_even_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut odd = vec![];
        let mut even = vec![];
        let mut is_odd = true;
        let mut head = head;
        while let Some(mut inner) = head {
            if is_odd {
                odd.push(inner.val);
            } else {
                even.push(inner.val);
            }
            is_odd = !is_odd;
            head = inner.next.take();
        }

        // note if we don't want to use reference, we need to construct
        // the ListNode in reverse order.
        let mut cur = None;
        for &v in even.iter().rev() {
            let mut node = ListNode::new(v);
            node.next = cur;
            cur = Some(Box::new(node));
        }

        for &v in odd.iter().rev() {
            let mut node = ListNode::new(v);
            node.next = cur;
            cur = Some(Box::new(node));
        }

        cur
    }
}
```
通过了之后看到别的大佬提交的代码，才知道原来O(1) space的解法应该怎样写。也整理如下：
```rust
impl Solution {
    pub fn odd_even_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy_list1 = Some(Box::new(ListNode::new(0)));
        let mut dummy_list2 = Some(Box::new(ListNode::new(0)));
        let mut tail_ptr1 = &mut dummy_list1;
        let mut tail_ptr2 = &mut dummy_list2;

        let mut is_odd = true; // first one is odd
        let mut cur = head;
        while let Some(mut cur_inner) = cur {
            cur = cur_inner.next.take();
            if is_odd {
                tail_ptr1.as_mut().unwrap().next = Some(cur_inner);
                tail_ptr1 = &mut tail_ptr1.as_mut().unwrap().next;
            } else {
                tail_ptr2.as_mut().unwrap().next = Some(cur_inner);
                tail_ptr2 = &mut tail_ptr2.as_mut().unwrap().next;
            }
            is_odd = !is_odd;
        }
        if let Some(node2) = dummy_list2.as_mut().unwrap().next.take() {
            tail_ptr1.as_mut().unwrap().next = Some(node2);
        }
        dummy_list1.unwrap().next
    }
}
```

PS：虽然我naive的解法看起来会比O(1) space的解法慢很多，但是提交后两者通过时间都是0ms，嗯，不愧是Rust。