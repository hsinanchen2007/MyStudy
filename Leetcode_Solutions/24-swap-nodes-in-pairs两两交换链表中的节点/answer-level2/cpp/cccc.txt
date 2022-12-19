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
    ListNode* swapPairs(ListNode* head) {
        /*非递归写法
        if(head == NULL || head->next == NULL)return head;     
        auto newhead = new ListNode(-1);
        newhead->next = head;

        auto front = newhead->next->next;
        auto behind = newhead;

        auto tmp = front->next;
        front->next = behind->next;
        behind->next->next = tmp;
        behind->next = front;
        front = behind->next->next;

        while(front->next && front->next->next){
            front = front->next->next;
            behind = behind->next->next;
            tmp = front->next;
            front->next = behind->next;
            behind->next->next = tmp;
            behind->next = front;
            front = behind->next->next;
        }
        return newhead->next;
        */
        if(head == NULL || head->next == NULL)return head; 
        auto tmp = swapPairs(head->next->next);
        head->next->next = head;
        auto newhead = head->next;
        head->next = tmp;
        return newhead;
    }
};
```