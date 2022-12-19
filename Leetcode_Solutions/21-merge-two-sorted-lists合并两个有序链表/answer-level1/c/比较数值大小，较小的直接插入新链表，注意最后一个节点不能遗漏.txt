### 解题思路
此处撰写解题思路

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
        ListNode* l = new ListNode(-1); //链表初始化
        ListNode* l3 = l;
        
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                l3->next = l1;;
                l1 = l1->next;
            }
            else
            {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        
        l3->next = l1 != NULL ? l1 : l2;

        return l->next;
    }
};
```