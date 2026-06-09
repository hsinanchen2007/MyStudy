方法一 
定义三个用于翻转链表的辅助指针（分别指向当前节点、当前节点的前一个节点、当前节点的下一个节点）和一个用于表示翻转链表头结点的指针。
翻转链表时，每次循环翻转一个结点需要判断该节点是否是最后一个结点。如果是最后一个节点，则翻转链表头指针指向该节点。
```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL;
        ListNode *nextptr=NULL;
        ListNode *cur=head;
        ListNode *rev=NULL;
        while(cur!=NULL){
            nextptr=cur->next;
            cur->next=prev;
            prev=cur;
            if(nextptr==NULL) rev=cur;
            cur=nextptr;
        }
        return rev;
    }
};
```
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
```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* p = reverseList(head->next); //链表最后一个节点，eg 1->2->4->6,即6
        head->next->next = head; //head为4，此处实现6->4
        head->next = NULL;// 断掉4->6
        return p;
    }
};
```

