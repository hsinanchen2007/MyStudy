### 解题思路
递归法解题
分为：前->head->next—>后
一个递归体的处理包括后面3部分（相当于一个循环体）
“前”和后面3部分的连接：head->next = swapPairs(next->next);

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
    ListNode* swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;


    }

};
```