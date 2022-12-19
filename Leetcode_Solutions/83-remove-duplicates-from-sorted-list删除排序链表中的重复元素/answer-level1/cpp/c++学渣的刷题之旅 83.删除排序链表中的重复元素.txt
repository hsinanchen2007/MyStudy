### 解题思路
留下链头用来返回，创造临时变量p用来检查重复元素。

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* p=head;
        while(p->next!=NULL){
            if(p->val==p->next->val){
                p->next=p->next->next;
                continue;
            }
            p=p->next;
        }
        return head;
    }
};
```