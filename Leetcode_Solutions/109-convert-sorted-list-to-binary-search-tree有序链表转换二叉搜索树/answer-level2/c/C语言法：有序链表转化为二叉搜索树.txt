    本题中需要注意二叉搜索树的中序序列既是递增的。而单链表中的序列也是递增序列。因此可以用递归法。利用快慢指针找到单链表的中间节点，使其作为二叉搜索树的根节点。链表左半部分和右半部分分别作为左子树和右子树**递归**实现。递归基例：链表
```


struct TreeNode* sortedListToBST(struct ListNode* head)
{
    if(head==NULL)
        return NULL;
    struct TreeNode *tree=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct ListNode *pre=head;
    struct ListNode *fast=head;
    struct ListNode *slow=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        pre=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    //这里注明一下：pre初始值如果是NULL，则后面无法给它赋值pre->next,如果初始值是head可能slow最终也指向了head，此时pre容易在二叉搜索树中被插入两次（递归的问题）
     tree->val=slow->val;
    if(slow==pre)  //如果这两个指针相等
        tree->left=NULL;
    else
    {
        pre->next=NULL;
        tree->left=sortedListToBST(head);
    }
    tree->right=sortedListToBST(slow->next);
    return tree;

}

```
