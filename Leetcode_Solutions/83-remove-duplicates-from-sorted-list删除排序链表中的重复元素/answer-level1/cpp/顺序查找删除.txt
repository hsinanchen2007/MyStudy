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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)//这句话我用head->next==NULL时结果是错的，但是我不知道为什么
            return head;
        ListNode *front=head;
        while(front->next!=NULL)
        {
            if(front->val==front->next->val)
            {
                ListNode *p=front->next;
                front->next=p->next;
                delete p;
            }
            else
            {
                front=front->next;
            }

        }

        return head;
    }
};
```
