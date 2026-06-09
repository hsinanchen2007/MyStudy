```
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* tail = head; // 指向当前最后一个奇数节点
        ListNode* front = NULL; // 指向当前最后一个偶数节点，该节点下一个即为待插入的奇数节点
        if(head)
        {
            front = head->next;
        }
        while(front && front->next)
        {
            ListNode* nodeToMove = front->next; // 待插入节点
            front->next = nodeToMove->next; // 脱链
            nodeToMove->next = tail->next; // 插入
            tail->next = nodeToMove; // 插入
            front = front->next;
            tail = tail->next;
        }
        return head;
    }
};
```