### 解题思路
首先定义一个答案节点， 然后每次遍历head链表，把点加到答案节点上。

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
        if(head == NULL){
            return head;
        }
        ListNode* ans = new ListNode(-1);
        ListNode* p = head;
        while(p != NULL){
            ListNode* temp = p -> next;

            p -> next = ans -> next;
            ans -> next = p;

            p = temp;
        }
        return ans -> next;
    }
};
```