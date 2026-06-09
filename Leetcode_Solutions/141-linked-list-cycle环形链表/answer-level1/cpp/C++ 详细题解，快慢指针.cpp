当快指针套圈慢指针，双指针相遇时，说明链表中存在环

常规的快慢指针解法，需要注意的是小心处理指针指向空指针的下一个指针（不存在）
```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *faptr = head;
        ListNode *slptr = head;
        while(faptr != nullptr && faptr -> next != nullptr)
        {
            faptr = faptr -> next -> next;
            slptr = slptr -> next;
            if(faptr == slptr)
                return true;
        }
        return false;
    }
};
```