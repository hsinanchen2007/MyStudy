### 解题思路
启用一个虚表头，两边一起遍历即可，最后把多的一个节点删掉。

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
        if (NULL == l1 && NULL == l2) return NULL;
        ListNode* re = new ListNode(0);
        ListNode* realhead = new ListNode(0);
        re->next = realhead;
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        while (NULL != ptr1 || NULL != ptr2) {
            re = re->next;
            if (ptr1 == NULL) {
                re->val = ptr2->val;
                ptr2 = ptr2->next;
            }
            else if (ptr2 == NULL) {
                re->val = ptr1->val;
                ptr1 = ptr1->next;                
            }
            else if (ptr1->val <= ptr2->val) {
                re->val = ptr1->val;
                ptr1 = ptr1->next;
            }
            else {
                re->val = ptr2->val;
                ptr2 = ptr2->next;       
            }
            ListNode* newNode = new ListNode(0);
            re->next = newNode;
        }
        re->next = NULL;
        return realhead;
    }
};
```