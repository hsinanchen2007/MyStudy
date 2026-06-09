### 解题思路
链表跨元素连接

### 代码

```cpp

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }

        ListNode*odd=head;
        ListNode*even=head->next;
        ListNode*evenHead=even;
        while(even!=NULL&&even->next!=NULL){
            odd->next=odd->next->next;
            odd=odd->next;
            even->next=even->next->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
    }
};
```