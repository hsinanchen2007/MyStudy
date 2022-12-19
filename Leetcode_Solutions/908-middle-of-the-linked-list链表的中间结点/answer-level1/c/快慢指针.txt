### 解题思路
慢指针移动一次，快指针移动两次
结果和结点数相关，奇数个结点，快指针走到尾部。偶数个结点，快指针走到倒数第二个结点。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *slow,*fast;
    slow=fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast->next!=NULL)
    return slow->next;
    return slow;
}
```