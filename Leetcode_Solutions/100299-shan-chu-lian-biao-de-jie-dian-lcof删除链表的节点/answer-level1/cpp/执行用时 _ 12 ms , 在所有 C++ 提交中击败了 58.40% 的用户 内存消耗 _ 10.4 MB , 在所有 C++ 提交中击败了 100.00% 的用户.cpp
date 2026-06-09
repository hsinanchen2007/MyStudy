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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head == NULL){
            return NULL;
        }

        if(val == head->val){
            head = head->next;
            return head;
        }

        ListNode* p = head;
        ListNode* newHead = p;
        while(p){
            ListNode* temp = p;
            p = p->next;
            if(p->val == val){
                temp->next = p->next;
                delete p;
                p = NULL;
                return newHead;
            }
        }
        return head;
    }
};
```