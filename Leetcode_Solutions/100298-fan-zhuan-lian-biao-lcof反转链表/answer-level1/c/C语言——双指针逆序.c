### 解题思路
双指针法/递归

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
    //双指针法
    if(head==NULL||head->next==NULL)return head;
    struct ListNode *p=NULL,*q=head,*temp=NULL;
    while(q!=NULL){
        temp=q->next;
        q->next=p;
        p=q;
        q=temp;
    }
    return p;
}
```

递归注意事项：使用head->next遍历到栈底并用指针记录，再通过head->next->next=head反指，head->next=NULL尾节点指向空。return 栈底指针