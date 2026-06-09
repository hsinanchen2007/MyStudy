```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
```
### 递归
```c++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
```
### 迭代
```c++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode test(-1);
        ListNode* s = &test;
        ListNode* pre = s; //pre指向已经排好序的最后一个节点
        while(l1 && l2){
            if(l1->val <= l2->val)
                pre->next  = l1,l1 = l1->next;
            else
                pre->next = l2,l2 = l2->next;
            pre = pre->next;
        }
        pre->next = (l1 == NULL) ? l2 : l1;
        return s->next;
    }
};
```
