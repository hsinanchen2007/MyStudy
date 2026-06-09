> 给定一个链表，判断链表中是否有环  

思路：快慢指针，循环整个链表，如果无环，那么fast指针终会指向NULL，若有环，slow和fast终会相遇。  

```c

执行用时 :12 ms, 在所有 C 提交中击败了83.90%的用户  
内存消耗 :8.6 MB, 在所有 C 提交中击败了5.60%的用户  

bool hasCycle(struct ListNode *head) {
    if(head == NULL)return false;
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)return true;
    }
    return false;
}
```
