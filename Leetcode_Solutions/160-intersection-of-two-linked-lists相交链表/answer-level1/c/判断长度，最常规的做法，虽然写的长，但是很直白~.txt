- 常规做法：就是让长的链表先走，当两个链表的剩余长度相同时，再每个节点判断一下。
- 需要注意的是，判断的标准不是两个链表的数据相同，而是两个链表相等。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL){
        return NULL;
    }
    struct ListNode * tmpA = headA;
    struct ListNode * tmpB = headB;
    int lenA = 0;
    int lenB = 0;
    while(tmpA != NULL)
    {
        lenA ++;
        tmpA = tmpA ->next;
    }
    while(tmpB != NULL)
    {
        lenB ++;
        tmpB = tmpB -> next;
    }
    tmpA = headA;
    tmpB = headB;
    if(lenA > lenB){
        for(int i = 0; i < (lenA - lenB); i++){
            tmpA = tmpA->next;
        }
    }else if(lenA < lenB){
        for(int i = 0; i < (lenB - lenA); i++){
            tmpB = tmpB->next;
        }
    }
    while(tmpA != NULL && tmpB != NULL){
        if(tmpA == tmpB){
            return tmpA;
        }
        tmpA = tmpA -> next;
        tmpB = tmpB -> next;
    }
    return NULL;
}
```
