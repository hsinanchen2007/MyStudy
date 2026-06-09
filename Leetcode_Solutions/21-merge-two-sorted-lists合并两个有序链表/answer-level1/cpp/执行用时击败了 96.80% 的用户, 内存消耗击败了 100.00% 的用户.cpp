### 解题思路
这道题目如果可以使用O(n1+n2)的内存空间，那么很简单。
但是如果是必须是真正的把l1 merge到l2或者把l2 merge到l1
这个复杂一些，不过只要清楚链表的插入即可


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
        ListNode* res = new ListNode(-1);
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* a = new ListNode(-1);
        ListNode* b = new ListNode(-1);
        if(l1->val <= l2->val){
            res->next = l1;
            a = l1; b = l2;
        }else{
            res->next = l2;
            a = l2; b = l1;
        }
        while(a->next && b){
            ListNode* b_next = new ListNode(-1);
            b_next = b->next;
            if(a->next->val >= b->val){
                ListNode* a_next = new ListNode(-1);
                a_next = a->next;
                a->next = b;
                b->next = a_next;
                //continue;
                a = a->next;
                b = b_next;
            }else{
                a = a->next;
            }
        }
        if(b){
            a->next = b;
        }
        return res->next;
    }
};
```

### 结果
执行用时 : 4 ms , 在所有 C++ 提交中击败了 96.80% 的用户 
内存消耗 : 6.7 MB , 在所有 C++ 提交中击败了 100.00% 的用户