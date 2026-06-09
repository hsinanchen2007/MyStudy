### 解题思路
当head为空时，说明链表为空，返回空链表（null）
当head.next为空，head为链表末端，返回当前节点
1->2->3->4->5->null
`last`用于存储返回的反转链表的头指针
head指向1 last指向5,2的next指向null
1 -> (2<-3<-4<-5)
然后head.next.next = head
1<-2<-3<-4<-5
head.next = null
null<-1<-2<-3<-4<-5
返回last即可
### 代码

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    if (head == null || head.next == null) return head;
    let last = reverseList(head.next);
    head.next.next = head;
    head.next = null;
    return last
};
```