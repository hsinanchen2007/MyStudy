### 解题思路
迭代方式实现，以1~5为例，将1指向3再将2指向1，就完成了前两个位置的交换，同理将1指向4再将3指向2.以此类推。

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
    if(head==NULL)
        return NULL;
    struct ListNode* pre=head;
    struct ListNode* cur=head->next;
    struct ListNode* tmp=NULL;
    while(cur!=NULL)
    {
        tmp=cur->next;
        pre->next = cur->next;
        cur->next = head;
        head=cur;
        cur=tmp;
    }
    return head;
}
```