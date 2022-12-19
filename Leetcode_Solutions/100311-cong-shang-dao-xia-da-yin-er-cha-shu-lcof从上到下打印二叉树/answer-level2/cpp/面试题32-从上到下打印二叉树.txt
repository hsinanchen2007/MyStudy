### 解题思路
分析一个例子：
```
    3
   / \
  9  20
    /  \
   15   7
```
输出根节点3的值时，考虑如何存储其左右子节点9和20。
有从左到右的要求，所以要先处理完左子节点9，这个时候9下面如果还有子节点也应该存好，放到20之后处理。
处理完9处理20。先到的先处理，因此想到队列。

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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> tmpQue;
        tmpQue.push(root);
        while(!tmpQue.empty())
        {
            TreeNode* tmpTreeNode = tmpQue.front();
            res.push_back(tmpTreeNode->val);
            if(tmpTreeNode->left != NULL)
                tmpQue.push(tmpTreeNode->left);
            if(tmpTreeNode->right != NULL)
                tmpQue.push(tmpTreeNode->right);
            tmpQue.pop();
        }
        return res;
    }
};
```