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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(p1->next != NULL){
            p1 = p1->next;
            if(p1->next != NULL) p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};
```