# Reverse in pairs #打卡

## Iteration
1. From 1->2->3->null to 3->2->1->null
2. Step 0: Initiate pre = null, cur = 1
2. Step 1: null 1->2->3->null
3. Step 2: null<-1 2->3->null
4. while cur != null, do Step 1 & 2


```python []
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        pre = None
        cur = head
        while cur != None:
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp
        return pre
```
```java []
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;
        while (cur != null){
            ListNode tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
}
```

## Recursion inspired by official solution

1. If there's only one element, return head
2. First we need to get the reversed linked list and then consider it and the current head like this
3. reversed: 3->2->null, current head: 1->2.
4. actually the layout is like:        
![reverse linked list.jpg](https://pic.leetcode-cn.com/942bf9c8ef36955e97a1e191f9e87830e8de3cd42c562bd63dd158c9ec183202-reverse%20linked%20list.jpg)

5. Finally We need to point 2 back to 1 and point 1 to null



```python []
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head
        p = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return p
```
```java []
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode p = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return p;
    }
}
```



