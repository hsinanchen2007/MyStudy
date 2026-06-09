### 解题思路
利用队列实现二叉树的层序遍历，在此基础上，将每层数据构成一个链表

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        //二叉树的层序遍历
        queue<TreeNode*>q;
        vector<ListNode*>res;
        q.push(tree);
        while(!q.empty()){
            ListNode* head=new ListNode(-1);//每层设置一个链表头节点
            ListNode* x=head;
            int l=q.size();
            for(int i=0;i<l;i++){
                TreeNode* t=q.front();
                ListNode* tl=new ListNode(t->val);
                x->next=tl;
                x=x->next;
                q.pop();
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            res.push_back(head->next);
        }
        return res;
    }
};
```