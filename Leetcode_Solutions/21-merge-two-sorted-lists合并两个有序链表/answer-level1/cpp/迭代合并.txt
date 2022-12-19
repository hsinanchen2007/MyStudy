### 解题思路
迭代定义：对前一次所得结果重复相同的运算过程

### 代码
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
        if(l1==NULL)
        {
            return l2;
        }

        if(l2==NULL)
        {
            return l1;
        }

        if(l1->val<l2->val)
        {
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;                             //把l1从栈顶弹出作为头节点
        }
        
        else
        {
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};
```