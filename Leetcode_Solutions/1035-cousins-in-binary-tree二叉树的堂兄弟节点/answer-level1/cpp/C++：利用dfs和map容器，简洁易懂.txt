### 解题思路
（1）用两个map容器分别保存每个节点的高度和父节点，key均为每个节点的val；
（2）用dfs得到每个节点的高度和父节点并保存到相应容器中；
（3）比较两个节点是否深度相同且父节点不同。
【注意】：
（1）每个节点的值不重复，因此用节点的值表示节点；
（2）当父节点为空时，用101表示，因为题目所给的节点的值在1~100之间
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
class Solution 
{
    map<int,int>depth;  //存储每个节点的深度
    map<int,int>parent;  //存储每个节点的父节点
public:
    bool isCousins(TreeNode* root, int x, int y) 
    {
        dfs(root,NULL);
        return depth[x]==depth[y] && parent[x]!=parent[y];
    }
    void dfs(TreeNode* node,TreeNode* par)
    {
        if (node!=NULL)
        {
            depth[node->val]=par!=NULL?1+depth[par->val]:0;
            parent[node->val]=par!=NULL?par->val:101;  //如果父节点为空，用101表示
            dfs(node->left,node);
            dfs(node->right,node);
        }
    }
};
```