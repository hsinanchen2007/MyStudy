简洁，大气
```c++ []
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fir=head, *sec=head;
        for(;fir->next;fir = fir->next)
            n--<1 && (sec = sec->next);
        n>0 ? head = head->next : sec->next = sec->next->next;
        return head;
    }
};
```
测试了一下，`?:`比`if else`效率高一点，`&&`和`if`差不多