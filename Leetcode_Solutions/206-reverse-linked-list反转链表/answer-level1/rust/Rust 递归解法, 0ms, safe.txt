
```rust
type Link = Option<Box<ListNode>>;
impl Solution {
    pub fn reverse_list(head: Link) -> Link {
        // 0ms, leet206, 递归版本
        fn rev(curLink: Link, prevLink: Link) -> Link {
            if let Some(mut p) = curLink {
                let nextLink = p.next;
                p.next = prevLink;
                return rev(nextLink, Some(p));
            }
            else { return prevLink; }
        }
        return rev(head, None);
    }
}
```
