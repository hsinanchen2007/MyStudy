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
    void swap (ListNode* pre) {
        if (pre == NULL) {
            return;
        }
        ListNode* cur = pre->next;      
        if (cur == NULL) {
            return;
        } 
        ListNode* next = cur->next;
        if (next == NULL) {
            return;
        }                
        pre->next = next;
        cur->next = next->next;
        next->next = cur; 
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode* newHead = new ListNode(0);
        ListNode* pre = head;
        if (pre == NULL) {
            return NULL;
        }
        ListNode* next = head->next;
        if (next == NULL) {
            return head;
        } 
        newHead->next = head;        
        bool change = true;
        pre = newHead;
        while (pre->next != NULL) {               
            if (!change) {
                change = true;
                pre = pre->next;
                continue;
            } else {
                change = false;
            }            
            swap(pre); 
            pre = pre->next;
        }
        return newHead->next;
    }
};
```