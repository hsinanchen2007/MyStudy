### 解题思路
执行用时击败41.08%；
题目的要求是求得所有等于sum的路径；
所以我们想象每一个节点都是根节点，再从每一个节点DFS找到它有几条等于sum的路径；
思路：
1、用DFS遍历所有的节点；
2、以第一步遍历到的当前节点为根节点，用DFS_Path找它有几条等于sum的路径。

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
    int re=0;
    int S=0;
    int pathSum(TreeNode* root, int sum) {
        //用DFS遍历所有的节点，再对所有的节点用DFS求path
        if (root==NULL) return re;
        S=sum;
        DFS(root);
        return re;
    }
    void DFS(TreeNode* root){//遍历所有的节点
        if (root==NULL) return;
        DFS_Path(root, 0);//以当前遍历到的节点，求有多少个等于sum的路径
        DFS(root->left);
        DFS(root->right);
    }
    void DFS_Path(TreeNode* root, int Sum){//求有多少个从根节点出发的路径
        if (root==NULL) return;
        if (Sum+root->val == S) re++;//上面的和+本节点的值==S
        DFS_Path(root->left, Sum+root->val);//和往下传递
        DFS_Path(root->right, Sum+root->val);
        return;

    }
};
```