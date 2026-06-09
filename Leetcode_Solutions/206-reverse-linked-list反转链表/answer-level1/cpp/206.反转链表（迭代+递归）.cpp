方法一 迭代
```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode *nextptr=NULL;
        while (cur != NULL) {
            nextptr = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextptr;
        }
        return prev;
    }
};
```
方法二 递归
假设链表为1->2->3->4->5，层层递归
1、当递归到最后reverseList(5)(head=head->next=4->next=5)时,head->next=NULL返回head(即5，p指向5),这层递归结束。
2、reverseList(5)(head->next=4->next=5)后的代码是head->next->next = head(5->next=4即5->4);head->next = NULL(4->NULL);return p(返回5->4->NULL);
3、再看reverseList(4)(head->next=3->next=4)后中后head->next->next = head(4->3);head->next = NULL(3->NULL);return p(返回5->4->3->NULL);
4、reverseList(2), reverseList(1)依次类推，p最终为5->4->3->2->1->NULL。
```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};
```