### 解题思路
利用链表的val表示状态，遍利链表时，val来标记，遇到已经标记了的，return 即可

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
 #define INF 0xfffffff
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        while(head){
            if(head->val==INF)return head;
            head->val=INF;
            head=head->next;
        }
        return nullptr;
    }
};
```