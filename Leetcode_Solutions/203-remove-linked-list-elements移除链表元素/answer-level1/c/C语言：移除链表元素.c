```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val){
    //如果头结点是要找的val，且不为NULL
    while(head && head->val == val) {
        head = head->next;
    }
    //如果头结点为NULL
    if(!head) {
        return head;
    }
    struct ListNode* p = head;
    //如果val位于中间或结尾
    while(p->next) {
        if(p->next->val == val) {
            p->next = p->next->next;
        } else {
            p = p->next;//遍历下一结点
        }
    }
    return head;
}
```
