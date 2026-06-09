### 解题思路
无论是使用递归还是非递归，核心思想都是一样的
1、找到最后一项和倒数第二项
2、最后一项指向倒数第二项，倒数第二项指向空
3、重复上述步骤遍历链表
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if ((head == NULL) || (head->next == NULL)) {
        return head;
    } else {
        struct ListNode* p = reverseList(head->next);  //递归找到head->next为最后一项的情况
        head->next->next = head;                       //最后一项指向head
        head->next = NULL;                             //倒数第二项变为最后一项指向NULL
        return p;
    }
}
```