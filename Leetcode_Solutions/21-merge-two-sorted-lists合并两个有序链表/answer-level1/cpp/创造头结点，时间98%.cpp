### 解题思路
没有头结点创造头结点法合并无头链表

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
        ListNode *head = (ListNode *)malloc(sizeof(ListNode));
        ListNode *p = head;
        while(l1 && l2){
            if(l1->val <= l2->val){
                p->next=l1; p=l1;
                l1=l1->next;
            }
            else{
                p->next=l2; p=l2;
                l2=l2->next;
            }
        }
        p->next=(l1)?l1:l2;
        return head->next;
    }
};
```