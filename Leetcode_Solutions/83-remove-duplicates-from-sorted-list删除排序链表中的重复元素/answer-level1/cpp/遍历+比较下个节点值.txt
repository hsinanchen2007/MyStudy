```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode *cur = head, *tmp = NULL;
        while (cur != NULL)
        {
            if((cur->next!=NULL) && (cur->val == cur->next->val))
            {
                tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
            {
                cur =  cur->next;                
            }
        }
        return head;
    }
    ListNode* deleteDuplicatesNoSort(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode *cur = head;
        while (cur != NULL)
        {
            cur->next = delNode(cur->next, cur->val);
            cur =  cur->next;
        }
        return head;
    }
    ListNode* delNode(ListNode* head, int val)
    {
        ListNode* cur = head, **ppcur = &cur;
        ListNode* tmp = NULL;
        while (*ppcur != NULL)
        {
            if ((*ppcur)->val == val)
            {
                tmp = (*ppcur);
                *ppcur = (*ppcur)->next;
                delete tmp;
            }
            else
            {
                ppcur = &((*ppcur)->next);
            }
        }
        return cur;
    }
};
```
