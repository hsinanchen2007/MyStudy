头结点加上 dummyhead指针，dummyhead指针前面有个fatherhead指针指着dummyhead

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        if(cur == NULL) return cur;
        ListNode* fatherHead = new ListNode (0);
        ListNode* dummyHead = new ListNode (0);
        dummyHead ->next = head;
        fatherHead ->next = dummyHead;
        while(cur->next != NULL){
            ListNode* tmp = cur->next;
            cur->next = tmp ->next;
            tmp->next = cur;
            dummyHead ->next = tmp;
            dummyHead = cur;
            cur = cur->next;
            if(cur == NULL) break;
        }
        return  fatherHead ->next->next;
        
    }
};
```
