### 解题思路
此处撰写解题思路
执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
6.5 MB
, 在所有 C++ 提交中击败了
100.00%
的用户
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL){return head;}
        ListNode  root(0);
        root.next=head;
        
        ListNode *prev=&root,*slow=head,*fast=head->next;
        while(prev!=NULL&&slow!=NULL&&fast!=NULL)
        {
            prev->next=fast;
            slow->next=fast->next;
            fast->next=slow;
            prev=slow;
            slow=slow->next;
            if(slow!=NULL)
            fast=slow->next;
        }
        return root.next;
    }
};
```