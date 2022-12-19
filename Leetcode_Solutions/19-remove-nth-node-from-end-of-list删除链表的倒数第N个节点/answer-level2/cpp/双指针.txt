### 解题思路
q指向要删除结点的前一结点

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = new ListNode(NULL);
        first -> next = head;  
        ListNode *p, *q;
        p = first;
        q = first;

        for( ;n >= 0; n--){
            p = p -> next;
        }
        while(p != NULL){
            p = p -> next;
            q = q -> next;
        }
        q -> next = q -> next -> next;
        return first -> next;
    }
};
```