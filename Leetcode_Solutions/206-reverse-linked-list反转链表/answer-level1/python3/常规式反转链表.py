### 解题思路

思路很简单：

- 当链表为空的时候，直接返回表头就可以。

- 如果链表不为空，那么可以分两种：

    - 链表第二个结点为空，那么还是返回表头。
    - 如果不为空，引入一个中间量 `tmp`，作为链表的搬运工，大家一起往前滚。

有段时间不写 C 了，多少有点手生。:)

Python 这里是用了多元赋值，思想是相近的。

快乐 Rust，没什么好说的。

### 代码

```c []
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL) {
        return head;
    }

    struct ListNode* cur = head;
    struct ListNode* pre = NULL;
    
    while(cur != NULL) {
        struct ListNode* tmp = cur;
        cur = tmp -> next;
        tmp -> next = pre;
        pre = tmp;
    };

    head -> next = NULL;
    head = pre;

    return head;
}
```

```python3 []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        pre, cur = None, head
        while cur:
            cur.next, pre, cur = pre, cur, cur.next
        return pre
```

```rust []
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut cur = head;
        let mut pre = None;

        while let Some(mut tmp) = cur {
            cur = tmp.next.take();
            tmp.next = pre;
            pre = Some(tmp);
        }
        pre
    }
}
```