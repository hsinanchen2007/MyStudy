### 解题思路
双指针，较容易理解

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
        ListNode* node=NULL;
        while(head!=NULL){
            ListNode *tmp=head->next;
            head->next=node;
            node=head;
            head=tmp;
        }
        return node;
    }
};
```