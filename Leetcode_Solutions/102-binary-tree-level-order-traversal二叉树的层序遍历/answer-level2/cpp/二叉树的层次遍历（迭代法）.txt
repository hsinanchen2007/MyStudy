### 解题思路
利用队列实现；
1.遍历当前层的时候，将其子树分别加入队列中；
2.该层遍历完成后，遍历下一层，依次将队列中的值出队列； 并将其子树压入另一个队列中。

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        queue<TreeNode*> current, next;    //两个队列，一个表示当前正在处理的，一个用来存子树的队列
        vector<int> level;
        if (root != NULL) current.push(root);
        while (!current.empty()) {
            while(!current.empty()) {
                TreeNode* tmp = current.front();     //取出当前节点
                current.pop();
                level.push_back(tmp->val);
                if (tmp->left != NULL) next.push(tmp->left); //将当前节点的左右子树放入另一个队列
                if (tmp->right != NULL) next.push(tmp->right);
            }
            //当前层遍历结束， 将结果放入数组中，清理参数，调整队列。
            result.push_back(level);      
            level.clear();
            swap(next, current);
        }
        return result;
    }
};
```