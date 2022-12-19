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
class Solution {
public:      //我自己写的方法，对是对，太慢了，结点重复遍历，我还感觉不对，但会结果对了。。
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL)
        return NULL;
        int count=0;
        DFS(root,count);
        return count;
    }
    int DFS(TreeNode *root,int &count){
        if(!root)
        return 0;
        if(root->val%2==0&&root->left)
        count=count+DFS(root->left->left,count)+DFS(root->left->right,count);
        if(root->val%2==0&&root->right)
        count=count+DFS(root->right->right,count)+DFS(root->right->left,count);
        DFS(root->left,count);//这里会重复走上面走过的路，但答案是真确的。。。
        DFS(root->right,count);
        return root->val;
    }

/*  方法2：用祖父节点和父节点的的值来隐喻他们 ，dfs遍历，没有跳层
private: 
    int ans=0;
public:  
 int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL)
        return NULL;
        dfs(1,1,root);
        return ans;
    }
    void dfs(int i,int j,TreeNode *node){
        if (!node) {
            return;
        }
        if (i % 2 == 0) {   
                ans += node->val;
        }
        dfs(j, node->val, node->left);
        dfs(j, node->val, node->right);
    }
*/

/*  方法一：
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL)
        return NULL;
        dfs(NULL,NULL,root);
        return ans;
    }
    void dfs(TreeNode * grandparent,TreeNode *parent,TreeNode *node){
        if (!node) {
            return;
        }
        if(!grandparent||!parent){      //这里思路不清晰，笨，这里应该是有一个为0就不执行语句(避免越界)
            dfs(parent, node, node->left);
            dfs(parent, node, node->right);
        }
        else
        {
            if (grandparent->val % 2 == 0) {
                ans += node->val;
            }
            dfs(parent, node, node->left);
            dfs(parent, node, node->right);
        } 
    } */
};
```