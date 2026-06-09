### 解题思路
递归算法深度优先遍历直到需要添加的层的时候，将需要添加的节点添加进去即可。

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1)//d = 1的情况实际上是从头部重新新建一个节点
        {
            TreeNode* temp = new TreeNode(v);
            temp->left = root;
            return temp;
        }else{
            dfs(root,1,v,d);//深度优先遍历
        }
        return root;
    }
    void dfs(TreeNode* node,int level,int v,int d)
    {
        if(!node) return;
        if(level == d - 1)//到达需要处理的节点了，需要一个临时变量来保存下一层的值。
        {
            TreeNode* tempL = node->left;
            TreeNode* tempR = node->right;
            TreeNode* currentL = new TreeNode(v);
            TreeNode* currentR = new TreeNode(v);
            node->left = currentL;
            node->right = currentR;
            currentL->left = tempL;
            currentR->right = tempR;
        }
        dfs(node->left,level + 1,v,d);//深度优先遍历
        dfs(node->right,level + 1,v,d);
    }
};
```