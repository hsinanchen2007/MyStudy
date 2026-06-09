### 解题思路
经过我做了一些leetcode，我发现在链表与树的题中，递归的方法几乎都适用，这一点令我很惊奇，开始拿到一道题，看到官方解递归，我
疯了，这都能用递归。

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
    if(head==NULL||head->next==NULL)
        return head;
    struct ListNode*p=head;
    //此处用于处理头结点，例如1，1，1，2，3，head=1，处理后2，3，head=2
    while(p->next&&p->val==p->next->val)
        p=p->next;
    if(p!=head)
        head=p->next;
    if(head==NULL||head->next==NULL)
        return head;
    //
    if(head->val!=head->next->val)
        head->next=deleteDuplicates(head->next);
    else
        return deleteDuplicates(head);
    return head;
}
```