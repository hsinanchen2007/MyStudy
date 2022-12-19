### 解题思路
第一次循环统计链表长度，第二次循环找到删除节点的前一个节点，如果删除头结点即(n==count)直接把头结点后移，否则正常删除即可。题中说n保证有效，所以一些判断n的有效性没有必要写

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
        if(head->next == nullptr)
            return nullptr;
        ListNode* rear = head;
        ListNode* temp = head;
        int count = 1;
        while(rear->next != nullptr){
            rear = rear->next;
            count++;
        }
        if(n==count)
            head=head->next;
        for(int i=0;i<count-n-1;i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};
```