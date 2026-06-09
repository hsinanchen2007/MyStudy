### 解题思路
迭代（C） + 递归（Java）

### 代码

```c
struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL)
        return NULL;
    struct ListNode *next, *prev, *t;
    prev = NULL;
    next = head->next;
    for(; next != NULL;){
        t = head;
        head = next;
        next = next->next;
        t->next = prev;
        prev = t;
    }
    head->next = prev;
    return head;
}
```
```java
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null)
            return null;
        return rec(null, head);
    }
    
    private ListNode rec(ListNode prev, ListNode next){
        if(next.next == null){
            next.next = prev;
            return next;   
        }
        ListNode t = next.next;
        next.next = prev;
        prev = next;
        next = t;
        return rec(prev, next);
    }

}
```