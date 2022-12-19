链表或者树的操作的题目尽量都考虑使用递归和迭代两种方法来做。
迭代：
```
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val==val)
            return head->next;
        ListNode* h =head;
        while(h->next->val!=val)
            h = h->next;
        h->next = h->next->next;
        return head;
    }
};
```
递归：
```
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val==val)
            return head->next;
        head->next = deleteNode(head->next,val);
        return head;
    }
};
```
