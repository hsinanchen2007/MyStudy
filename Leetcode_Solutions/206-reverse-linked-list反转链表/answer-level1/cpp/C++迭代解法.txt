很简单的思路：
只需要先找到链表的最后一个节点，并存储，作为反转后的链表的const head指针。整个过程只需要将原链表中的第一个节点插入原链表中最后一个节点之后即可。代码如下：
```
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* tail = findTail(head);
        ListNode* cur = head;
        while(cur!=tail){
            head = head->next;
            insert_next(tail, cur);
            cur=head;
        }
        return tail;
    }

    ListNode* findTail(ListNode* head);
    ListNode* insert_next(ListNode* head, ListNode* node);
};

ListNode* Solution::findTail(ListNode* head){
        ListNode* cur=head;
        if(cur==NULL) return head;
        while(cur->next!=NULL) cur=cur->next;
        return cur;
    }

ListNode* Solution::insert_next(ListNode* head, ListNode* node){
    node->next=head->next;
    head->next=node;
    return head;
}
```
