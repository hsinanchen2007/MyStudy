### 解题思路

首先分析完全二叉树的性质

1. 每一层的结点全部靠左，因此我们在遍历每一层时，要判断这一点，我这里用一个flag来判断空结点后是否还有结点
2. 完全二叉树只有最后一层不是满的，前面1-n-1层全部满足2次幂

对于1 我们在层次遍历时用flag判断是否结点全部靠左
对于2 我们用一个map<int,vector<int>> 来存储每一层的结点

解决了这两点就ac了这道题

菜鸡解法，效率还行

![捕获.PNG](https://pic.leetcode-cn.com/98a20f095da245b6a73c961307efa24211b56d0eaa44ea67d31cc261418b559f-%E6%8D%95%E8%8E%B7.PNG)

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
class Solution {
public:
    map<int,vector<int>> res;
    bool m=true;
    int depth=0;
    bool isCompleteTree(TreeNode* root) {
        help(root,0);
        int a=res.size();
        for(int i=0;i<a-1;i++)
        {
            if(res[i].size()!=pow(2,i))
                return false;
        }
        return m;

    }
    void help(TreeNode* root,int depth)
    {
        queue<TreeNode*> q;
        q.push(root);
        res[0].push_back(root->val);
        while(!q.empty())
        {
            int n=q.size();
            int flag=0;
            depth+=1;
            while(n>0)
            {   
                    auto node=q.front();
                    q.pop();
                    if(flag==1&&(node->left!=NULL||node->right!=NULL))
                    {
                        m=false;
                        return;
                    }
                    if(node->left!=NULL)
                    {
                        q.push(node->left);
                        res[depth].push_back(node->left->val);
                    }
                        
                    if(node->right!=NULL)
                    {
                        q.push(node->right);
                        res[depth].push_back(node->right->val);
                    }
                       
                    if(node->left==NULL&&node->right!=NULL)
                    {
                        m=false;
                        return;
                    }
                    if(node->left==NULL)
                        flag=1;
                    if(node->right==NULL)
                        flag=1;
                
                --n;
            }
        }
    }
};
```