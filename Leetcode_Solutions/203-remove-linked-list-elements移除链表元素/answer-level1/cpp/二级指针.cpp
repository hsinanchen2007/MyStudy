我偏不用哨兵
```cpp
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode **p = &head;
        while(*p){
            if((*p)->val==val)*p = (*p)->next;
            else p = &(*p)->next;
        }
        return head;
    }
};
```