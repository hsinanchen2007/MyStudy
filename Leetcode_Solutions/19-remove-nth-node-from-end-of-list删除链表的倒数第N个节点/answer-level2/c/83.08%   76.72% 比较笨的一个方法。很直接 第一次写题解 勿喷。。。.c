### 解题思路


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head==NULL) return NULL;
    struct ListNode* Head = head;
    struct ListNode* plen = head;
    int len = 1;
    //计算链表长度
    while(plen->next!=NULL){
        plen=plen->next;
        len++;
    }
    //如果删除第一个元素 直接返回头节点下一个
    if(n==len) return head->next;
    //工作指针要移动的次数
    int move = len-n-1;
    while(move!=0) {Head=Head->next;move=move-1;}
    struct ListNode* q = Head->next;
    Head->next=q->next;
    free(q);
    return head;
}
```