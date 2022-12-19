### 解题思路
判断 头节点是否为空，不为空则判断头节点值和下一个节点值是否相等，相等则把指针指向下一个节点，不相等则跳到下一个节点
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* temp;
    temp =  head;
    while(temp!=NULL){
        while(temp->next!=NULL && temp->val == temp->next->val){
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
    return head;
}
```