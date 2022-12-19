### 解题思路
此处撰写解题思路
1.迭代法：定义两个指针，一个指向当前节点（cur），一个指向当前节点的前一个节点（pre）
2.递归法：链表内部函数递归的关键函数语句为：head->next->next = head
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//迭代法：
/*struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;
    struct ListNode* tmp = NULL;

    while( cur != NULL ){
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}*/

//递归法：
struct ListNode* reverseList(struct ListNode* head){
    if( head == NULL || head->next == NULL ){
        return head;
    }
    struct ListNode* cur = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return cur;
}



```