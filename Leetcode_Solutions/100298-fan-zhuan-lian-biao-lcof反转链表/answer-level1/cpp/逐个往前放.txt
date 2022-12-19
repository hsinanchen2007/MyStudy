### 解题思路
此处撰写解题思路

### 代码
能让我一次过的题着实不多。
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
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        ListNode* p = head;
        while(p->next != NULL){
            ListNode* pNew = new ListNode(p->next->val);
            pNew->next = head;
            head = pNew;
            p->next = p->next->next;
        }
        return head;
    }
};
```