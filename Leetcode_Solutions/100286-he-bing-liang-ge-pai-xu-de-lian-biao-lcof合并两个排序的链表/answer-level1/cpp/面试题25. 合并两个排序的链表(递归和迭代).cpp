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
        // 递归版本， 参看大佬的，不过递归版本会慢点
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        if(l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        l2->next = mergeTwoLists(l2->next, l1);
        return l2;

        
        // 迭代版本
        // if(l1 == NULL && l2 == NULL)
        //     return NULL;
        // else if(l2 == NULL)
        //     return l1;
        // else if(l1 == NULL)
        //     return l2;

        // ListNode* res;
        // if(l1->val <= l2->val)
        // {
        //     res = l1;
        //     l1 = l1->next;
        // }
        // else
        // {
        //     res = l2;
        //     l2 = l2->next;
        // }
        // ListNode* head = res;
        // while(l1 != NULL && l2 != NULL)
        // {
        //     if(l1->val <= l2->val)
        //     {
        //         res->next = l1;
        //         res = res->next;
        //         l1 = l1->next;
        //     }
        //     else
        //     {
        //         res->next = l2;
        //         res = res->next;
        //         l2 = l2->next;
        //     }
                
        // }
        // if(l1)
        //     res->next = l1;
        // else if(l2)
        //     res->next = l2;
        // return head;
    }
};
```