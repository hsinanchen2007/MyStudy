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
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head, *tail = nullptr;
        while (head != nullptr){
            head = head-> next;
            cur -> next = tail;
            tail = cur;
            cur = head;
        } ;
        return tail;
    }
};
```