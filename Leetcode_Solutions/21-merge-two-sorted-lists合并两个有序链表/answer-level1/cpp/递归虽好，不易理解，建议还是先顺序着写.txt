### 解题思路
递归虽好，不易理解，建议还是先顺序着写

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
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *l = NULL;
        //直接使用l1, l2，尽量节省空间
        if(l1->val < l2->val)
            l = l1, l1 = l1->next;
        else
            l = l2, l2 = l2->next;
        ListNode *p = l;
        while(l1 && l2){
            if(l1->val < l2->val){
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1?l1:l2;
        return l;
    }
};
```