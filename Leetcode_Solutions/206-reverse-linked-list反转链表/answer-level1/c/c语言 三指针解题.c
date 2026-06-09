### 解题思路

### 代码

思路如注释

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *tem = NULL, *p = head;//定义指针tem，p与head指向头结点
    while(head != NULL){           //当头结点不为空时
        head = head->next;         //head指针向后移
        p->next = tem;             //该结点指向前一个节点
        tem  = p;                  //反转后被指结点指针前移
        p = head;                  //p指针指向下一个反转指针节点
    }
    return tem;

}


```