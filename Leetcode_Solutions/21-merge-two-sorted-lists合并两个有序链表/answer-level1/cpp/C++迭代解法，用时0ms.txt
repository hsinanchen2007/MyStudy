![Snipaste_2020-03-15_07-50-21.png](https://pic.leetcode-cn.com/4689f8dd28b53b94a957c43aa9b57831d098f92bfdaa4c681cf8395ba3fe1c67-Snipaste_2020-03-15_07-50-21.png)
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //ListNode*p = l1,*q = l2;    //不定义头结点更简洁
        ListNode guard(-1);
        ListNode*pre = &guard;
        while(l1!=nullptr&&l2!=nullptr)
        {
            if(l1->val<=l2->val)
            {
                pre->next = l1;
                l1 = l1->next;
            }
            else
            {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        pre->next = (l1==nullptr)? l2:l1;
        return guard.next;
        
    }
};
```

