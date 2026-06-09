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
    //递归解法
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //    if(!l1) return l2;
    //    if(!l2) return l1;
    //    if(l1->val<l2->val){
    //        l1->next=mergeTwoLists(l1->next,l2);
    //        return l1;

    //    }else{
    //        l2->next=mergeTwoLists(l1,l2->next);
    //        return l2;
    //    }

    // }

    //归并解法

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while(l1 && l2)
        {
            if(l1->val <l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 :l2;//处理l1或者l2有剩余的情况
        return dummy->next;
    }
};
```