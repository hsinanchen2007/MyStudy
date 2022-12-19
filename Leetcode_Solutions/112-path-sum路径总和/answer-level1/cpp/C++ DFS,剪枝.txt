### 解题思路
1、判断边界条件。1）root为null。2）root左右子树为null。
2、深度搜索左右子树。

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
    void DFS(TreeNode *Node,int sum ){
        if(Node==NULL){return;}
        sum-=Node->val;
        if(Node->left==NULL&&Node->right==NULL&&sum==0){
            flag=true;
            return;
        }
        else{
            DFS(Node->left,sum);
            DFS(Node->right,sum);
            sum+=Node->val;
        }
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL){return false;}
        DFS(root,sum);        
        return flag;
    }
protected:
    bool flag=false;
};
```