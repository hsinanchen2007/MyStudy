### 解题思路
本题有两种思路，一种是迭代，一种是递归。
迭代：由于两个链表均为有序链表，只需要比较两个链表中的结点大小，将较小结点依次加在新链表后即可。
递归：该问题可化解为：头结点较小的链表结点作为头结点，并合并其余下链表与另一链表，边界条件为：链表为空

### 代码

## 迭代法
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
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        if(l1 == nullptr && l2 == nullptr)
            return l1;
        ListNode *head = new ListNode(0), *p;
        p = head;
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            } else {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }
        p->next = l1 != nullptr? l1 : l2;
        return head->next;
    }
};
```

## 递归法：
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
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        if(l1 == nullptr && l2 == nullptr)
            return l1;
        if(l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;  
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;  
        }
    }
};
```