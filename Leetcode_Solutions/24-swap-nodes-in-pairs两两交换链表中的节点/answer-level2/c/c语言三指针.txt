### 解题思路
此处撰写解题思路
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head){
    if(head == NULL) return NULL;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* p1 = head;  //前结点
    struct ListNode* p2 = head->next;   //后节点
    struct ListNode* p3 = dummy;  //用来连接交换后的链表
    while(p2 != NULL){
        p3->next = p2;  //链接新的头
        p1->next = p2->next;
        p2->next = p1;
        p3 = p1;
        if(p1->next == NULL) break;
        p1 = p1->next;    //节点移动
        p2 = p1->next;
    }
    return dummy->next;
}
```