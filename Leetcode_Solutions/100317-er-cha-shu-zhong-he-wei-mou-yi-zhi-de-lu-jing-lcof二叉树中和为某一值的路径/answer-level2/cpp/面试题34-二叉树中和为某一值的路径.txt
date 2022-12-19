### 解题思路
- 首先读懂题意，路径必须是从根节点到叶节点，所以不能是到一半的路径，因此必须走到叶节点。
- 方法肯定是递归，当走到某一节点时，应该把节点添加到路径，并累加该节点的值。
- 如果该结点为叶结点并且和等于sum则返回路径。若不满足，则继续访问它的子节点。
- 访问结束，应该回退到上一个结点，尝试这个结点的其他路径，此时要把当前节点从路径中删除，和也减去当前val。
- 所以数据结构是一个栈，返回的时候要弹出。
- 总结得到：需要存储的有，路径和当前的和值，数据结构是栈，方法是递归。

### C++代码

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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        if(root == NULL)
            return res;
        isPathSun (root,path,0,sum);
        return res;
    }
    void isPathSun (TreeNode* node, vector<int>& path,int curSum,int sum)
    {
        curSum += node->val;
        path.push_back(node->val);
        if((node->left == NULL) && (node->right == NULL) && curSum == sum)
        {
            res.push_back(path);
        }
        if(node->left != NULL)
            isPathSun(node->left,path,curSum,sum);
        if(node->right != NULL)
            isPathSun(node->right,path,curSum,sum);
        path.pop_back();
        curSum -= node->val;
    }
};
```