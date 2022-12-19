执行用时 :4 ms, 在所有 C++ 提交中击败了90.26%的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了72.97%的用户

```
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return head;
        }
        ListNode* fateHead = new ListNode(0);
        fateHead->next = head;
        ListNode* beforeNode = fateHead;
        ListNode* curNode;
        curNode = head;
        while (curNode != NULL && curNode->next != NULL) {
            ListNode* temp = curNode->next;
            beforeNode->next = temp;
            curNode->next = temp->next;
            temp->next = curNode;
            beforeNode = curNode;
            curNode = curNode->next;
        }
        return fateHead->next;
    }
};
```
