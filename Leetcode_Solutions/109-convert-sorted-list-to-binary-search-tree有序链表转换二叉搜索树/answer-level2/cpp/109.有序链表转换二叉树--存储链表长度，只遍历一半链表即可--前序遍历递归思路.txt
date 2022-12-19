### 解题思路
此处撰写解题思路
![2019-12-31_191731.png](https://pic.leetcode-cn.com/7288b8eae4de5320aa3104d357aad0b6614d31d0917fb61e2ea4c13c95a57990-2019-12-31_191731.png)
采用空间换取时间的方法提高运行效率，头结点存储INT_MAX，下一个结点存储结点个数len，接着存储len个结点的链表。
头结点存储INT_MAX，是为了识别下一个结点是否是链表长度。这样知道这个链表长度后，就可以每次只遍历一半链表即可。
为充分考虑时间和空间的效率，可以把len定在len>N时，采用这种方法，以便在时间和空间上更好的平衡。
### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
        {
            return nullptr;
        }
        ListNode* h=head;
        int len=0;
        if(head->val!=INT_MAX)
        {
            while(h)
            {
                len++;
                h=h->next;
            }

        }
        else
        {
            //取链表长度
           len=head->next->val;
           head=head->next->next;
        }
        if(!head)
        {
            return nullptr;
        }
        if(len==1)
        {
            TreeNode *t =new TreeNode(head->val);
            return t;
        }
        int n=0;
        h=head;
        ListNode *pre=h;
        while(n<len/2)
        {
            pre=h;
            h=h->next;
            n++;
        }
        //建立根节点
        TreeNode *t =new TreeNode(h->val);
        //左子树head
        pre->next=NULL;
        //右子树h
        h=h->next;
        //带头结点的链表，头结点数值存储左子树的结点个数
        static ListNode* tmax=new ListNode(INT_MAX);
        if(len>650)
        {
            tmax->next = new ListNode(n);
            tmax->next->next=head;
            t->left=sortedListToBST(tmax);
        }
        else
            t->left=sortedListToBST(head);
        //带头结点的链表，头结点数值存储右子树的结点个数
        if(len>650)
        {
            tmax->next =new ListNode(len-n-1);
            tmax->next->next=h;
            t->right=sortedListToBST(tmax);
        }
        else
            t->right=sortedListToBST(h);
        return t;
    }
};
```