### 解题思路
发现小于X的节点将其放到链表头部即可。

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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode*tmp=head;
        while(tmp->next){
            if(tmp->next->val<x){
                ListNode*now=tmp->next;
                tmp->next=now->next;
                now->next=head;
                head=now;
            }
            else{
                tmp=tmp->next;
            }
        }
        return head;
    }
};
```