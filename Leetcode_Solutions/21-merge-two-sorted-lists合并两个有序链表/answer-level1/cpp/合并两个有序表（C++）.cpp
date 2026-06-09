### 解题思路
类似于归并排序的思想。
若l1和l2都为空，返回NULL;
若l1和l2有一个为空，返回非空的；
若都不为空，每次从两个链表表头取一个节点比较，将val较小者尾插到新链表中。直到有一个链表为空，再将另一个链表链到新链表后即可。

### 代码

```cpp
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)
            return NULL;
        if(!l1 && l2)
            return l2;
        if(l1 && !l2)
            return l1;

        ListNode* head = new ListNode(-1);
        ListNode* p = head, *q;

        while(l1 && l2){
            if(l1->val < l2->val){
                q = new ListNode(l1->val);
                p->next = q;
                p = q;
                l1 = l1->next;
            }
            else{
                q = new ListNode(l2->val);
                p->next = q;
                p = q;
                l2 = l2->next;
            }
        }

        if(l1)
            l2 = l1;
        p->next = l2;

        return head->next;
    }
};