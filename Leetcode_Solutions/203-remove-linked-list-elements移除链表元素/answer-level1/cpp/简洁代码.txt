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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p = new ListNode(-1), *q = p;
        q->next = head;
        while(q != NULL){
            if(q->next != NULL && q->next->val == val){
                q->next = q->next->next;
            }else q = q->next;
        }
        return p->next;
    }
};
```