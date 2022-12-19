
## 迭代

```go
func reverseList(head *ListNode) *ListNode {
    if head == nil {
		return head
	}
	cur := head
	var prev *ListNode = nil
	for cur != nil && cur.Next != nil {
		next := cur.Next
		cur.Next = prev
		prev = cur
		cur = next
	}
	cur.Next = prev
	return cur
}
```

```javascript
var reverseList = function(head) {
    if (head == null) return head
    let cur = head, pre = null
    while (cur != null && cur.next != null){
        let next = cur.next
        cur.next = pre
        pre = cur
        cur = next
    }
    cur.next = pre
    return cur
};
```

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        while (cur){
            ListNode* next = cur-> next;
            cur-> next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
```

## 递归

![206.reverse-linked-list.png](https://pic.leetcode-cn.com/b919430e6e4c940268d689e40c8e96d3c6434e9a7756d206de760bdec61522b0-file_1583135125249)

```javascript
var reverseList = function(head) {
    if (head == null || head.next == null) return head
    let next = reverseList(head.next)
    head.next.next = head
    head.next = null
    return next
};
```

```go
func reverseList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    next := reverseList(head.Next)
    head.Next.Next = head
    head.Next = nil
    return next
}
```

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL ) return head;
        ListNode* cur = reverseList(head->next); // head->next的反转结果，返回链表头
        head->next->next = head; // 头部两个元素进行反转
        head->next = NULL;
        return cur;
    }
};
```
