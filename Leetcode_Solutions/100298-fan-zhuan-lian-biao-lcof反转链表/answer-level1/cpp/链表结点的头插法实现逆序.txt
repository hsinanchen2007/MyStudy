```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* first = NULL;
        while(head!=NULL){

            ListNode* result = new ListNode(head->val);
            result->next = first;
            first = result;
            head = head->next;

        }
        return first;
    }
};
```
    遍历已有链表，对每个元素实行头插法插入到一个新的链表当中从而完成逆序。
