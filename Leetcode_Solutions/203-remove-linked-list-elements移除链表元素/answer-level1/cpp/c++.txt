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
    ListNode* removeElements(ListNode* head, int val) {
        //先确保头结点不是要删除的结点
       while(head&&head->val==val)
       {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
       }
        //然后就是普通的链表非头结点的删除
       ListNode*p = head;
       while(p)
       {
           if(p->next&&p->next->val==val)
           {
               ListNode* q = p->next;
               p->next = q->next;
               delete q;
           }
           else
           {
               p = p->next;
           }
       }
       return head;
    }
};
```
