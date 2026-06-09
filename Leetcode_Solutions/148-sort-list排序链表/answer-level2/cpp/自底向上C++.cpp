自底向上C++
主要分为以下几块：1.合并两个以NULL为尾结点的list 2. 寻找部分有序的链表的头部节点 3.主函数注意合并到了末尾的时候的情况的处理
```
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int size = 0;
        ListNode* it = head;
        while (it) {
            size++;
            it = it->next;
        }
        if (size <= 1) return head;
        
        int gap = 1;
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        ListNode *head1 = head, *head2, *nextHead1;
        while (gap < size) {
            head2 = findNextHead(head1, gap);
            nextHead1 = findNextHead(head2, gap);
            tail = merge(tail, head1, head2);
            head1 = nextHead1;
            if (head1 == NULL) {
                gap += gap;
                head1 = dummy->next;
                tail = dummy;
            }
        }
        return dummy->next;
    }
    
    ListNode* findNextHead(ListNode* head, int gap) {
        if (head == NULL) return NULL;
        ListNode *cur = head, *pre = NULL;
        for (int i = 0; i < gap; i++) {
            pre = cur;
            cur = cur->next;
            if (cur == NULL) return NULL;
        }
        if (pre) pre->next = NULL;
        return cur;
    }
    
    ListNode* merge(ListNode* tail, ListNode* head1, ListNode* head2) {
        ListNode *it1 = head1, *it2 = head2;
        while (it1 || it2) {
            if (it1 && it2) {
                if (it1->val <= it2->val) {
                    if (tail) tail->next = it1;
                    tail = it1;
                    it1 = it1->next;
                } else {
                    if (tail) tail->next = it2;
                    tail = it2;
                    it2 = it2->next;
                }
            } else if (it1) {
                if (tail) tail->next = it1;
                tail = it1;
                it1 = it1->next;
            } else {
                if (tail) tail->next = it2;
                tail = it2;
                it2 = it2->next;
            }
        } 
        return tail;
    }
};
```