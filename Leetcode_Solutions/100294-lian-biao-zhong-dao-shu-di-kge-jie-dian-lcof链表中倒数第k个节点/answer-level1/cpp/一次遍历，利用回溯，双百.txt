
```
class Solution {
public:
    int tail;      //到尾部时置零，回溯时不断加一
    ListNode *res;
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(head == nullptr){ 
            tail = 0;
            return nullptr;
        }
        getKthFromEnd(head->next, k);
        ++tail;
        if(k == tail)
            res = head;
        return res;
    }
};
```
