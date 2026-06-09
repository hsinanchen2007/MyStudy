### 解题思路
创建一个哈希表，键为节点，值为以此节点为根的子树的最大深度。先递归遍历树，更新哈希表；然后再次递归遍历树，当前节点没有子树时，此节点就是答案；若只有左节点，则答案在左子树中，若只有右节点，则答案在右子树中；若左右节点都存在，左右节点的哈希值相等，输出此节点；否则答案在哈希值较大的那棵子树中。
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
    map<TreeNode*, int> nodes;  //存储以节点为根的子树的最大深度
    TreeNode* ans;
    int firstDeepth(TreeNode* root, int nowDeepth)  
    {
        if(root == NULL) return nowDeepth - 1;  //节点为空，返回当前深度减1
        int lefts = firstDeepth(root -> left, nowDeepth + 1);  //得到左子树的最大深度
        int rights = firstDeepth(root -> right, nowDeepth + 1);  //得到右子树的最大深度
        nodes[root] = max(lefts, rights);  //当前节点对应的是左右节点的最大值
        return max(lefts, rights);
    }
    void secondDeepth(TreeNode* root)
    {
        if(root -> left == NULL && root -> right == NULL) ans = root;  //没有子节点
        else if(root -> left && root -> right)   //左右节点的最大深度相同
        {
            if(nodes[root -> left] == nodes[root -> right]) ans = root;
            else if(nodes[root -> left] < nodes[root -> right]) secondDeepth(root -> right);
            else secondDeepth(root -> left);
        }
        else   //只有左子树或只有右子树
        {
            if(root -> left == NULL) secondDeepth(root -> right);
            else secondDeepth(root -> left);
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int deepth = firstDeepth(root, 0);
        secondDeepth(root);
        return ans;
    }
};
```