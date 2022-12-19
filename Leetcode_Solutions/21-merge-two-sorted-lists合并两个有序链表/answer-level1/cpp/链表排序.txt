### 解题思路
可以作为一个归并排序来求解
新建一个链表头head，但是这个头并不存储数据，是固定的
比较两个链表的数值。较小的放在新链表的节点上，注意每进行一步操作要将相应的节点进行后移操作。

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
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                tail->next = l1;
                l1 = l1->next;
                tail = tail->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
                tail = tail->next;
            }
        }
        while(l1 != NULL){
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }

        while(l2 != NULL){
            tail->next = l2;
            l2 = l2->next;
            tail = tail->next;
        }

        return head->next;
    }
};
```