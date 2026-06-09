对于给的是 `Box` 而不是 `Rc` 这种共享指针表示很蛋疼，暂时想不到什么好的实现方法，用的是将这些链表收到一个 vector 里面，然后调用vec的sort，之后再用这个vec构造一个链表并返回.

```Rust
impl Solution {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        if lists.is_empty() {
            return None;
        }
        let mut n = 0; 
        // compute length
        for mut ref_option in lists.iter() {
            while let Some(ref ref_box) = *ref_option {
                n += 1;
                ref_option = &ref_box.next;
            }
        }
        if n == 0 {
            return None;
        }

        // push into a vector
        let mut v = Vec::with_capacity(n);
        for mut ref_option in lists.iter() {
            while let Some(ref ref_box) = *ref_option {
                v.push(ref_box.val);
                ref_option = &ref_box.next;
            }
        }
        // sort
        v.sort();

        //generate a linklist
        let mut head = Some(Box::new(ListNode::new(v[0])));
        let mut prev: &mut Box<ListNode> = head.as_mut().unwrap();
        for &i in v[1..].iter() {
            prev.next = Some(Box::new(ListNode::new(i)));
            prev = prev.next.as_mut().unwrap();
        }
        head
    }
}
```

用时 4ms， 内存 3.1m，其实算不上是好的方法，相当于 k个**有序** 链表这个条件根本没用，可能是Rust底层 vector 性能比较高的原因吧。