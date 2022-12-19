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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return head;
        }    
        ListNode* list1 = head;
        ListNode* list2 = head->next;

        ListNode* node1 = head;
        ListNode* node2 = head->next;
        while(node1 && node1->next && node2->next) {
            node1->next = node2->next;
            node1 = node1->next;
            node2->next = node1->next;
            node2 = node2->next;   
        }
        node1->next = list2;
        return head;
        
    }
};
```