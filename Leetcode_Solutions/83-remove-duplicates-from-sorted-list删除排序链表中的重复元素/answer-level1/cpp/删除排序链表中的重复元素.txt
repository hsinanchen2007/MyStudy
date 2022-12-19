```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
```

- step 1: 如果head为空直接返回即可
- step 2: 定义current_node用于遍历
- step 3: 在遍历时，判断如果下一结点与当前结点值相同，则删除下一结点
- step 4: 返回head

```c++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
    
        ListNode *current_node = head;
    
        while (current_node->next) {
            ListNode* next_node = current_node->next;
            if (current_node->val == next_node->val) {
                current_node->next = next_node->next;
                delete next_node;
                next_node = NULL;
            }
            else
                current_node = next_node;
        }
        
        return head;
    }
    
};
```