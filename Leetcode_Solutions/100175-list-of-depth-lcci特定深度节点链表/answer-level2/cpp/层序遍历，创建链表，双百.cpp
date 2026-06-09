### 解题思路
此处撰写解题思路

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
        vector<ListNode *>res;
        if(NULL==tree)  return res;
        queue<TreeNode *>Q;
        Q.push(tree);
        while(Q.size())
        {
            int count = Q.size();
            ListNode * head =new ListNode(0);
            head->next=NULL;
            ListNode *temp=head;
            for(int i=0;i<count;i++)
            {
                TreeNode *node = Q.front();
                Q.pop();
                ListNode * templistnode =new ListNode(node->val);
                templistnode->next = NULL;
                head->next =templistnode;
                head=head->next;
                if(node->left) Q.push(node->left);
                if(node->right) Q.push(node->right);
            }
            res.push_back(temp->next);
        }
        return res;
    }
};
```