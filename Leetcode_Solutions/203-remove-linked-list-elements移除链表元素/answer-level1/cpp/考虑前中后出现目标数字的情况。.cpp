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
        if(!head){
            return NULL;
        }
        while(head->val==val){
            head = head->next;
            if(!head) return NULL;
        }
        ListNode* tempNode = head;
        ListNode* ptr = head->next;
        while(ptr){
            if(ptr->val==val && ptr){
                while(ptr->val==val){
                    ptr = ptr->next;
                    if(!ptr) break;
                }
                tempNode->next = ptr;
            }
            if(!ptr) break;
            ptr = ptr->next;
            tempNode = tempNode->next;
                
        }
        return head;
    }
};
```