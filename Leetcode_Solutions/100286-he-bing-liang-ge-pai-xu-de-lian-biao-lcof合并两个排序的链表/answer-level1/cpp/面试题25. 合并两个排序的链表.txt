```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 1. 递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        return NULL;

    }
};
// 2. 迭代
class Solution {    
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        // if (l1 == NULL)  //迭代解法不必判断
        //     return l2;
        // if (l2 == NULL)
        //     return l1;

        ListNode * dummyHead = new ListNode(0);
        ListNode * p = dummyHead;

        while (l1 && l2) {
            
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }

        p->next = l1 ? l1 : l2;

        ListNode * ret = dummyHead->next;
        delete dummyHead;
        return ret;

    }
};


```