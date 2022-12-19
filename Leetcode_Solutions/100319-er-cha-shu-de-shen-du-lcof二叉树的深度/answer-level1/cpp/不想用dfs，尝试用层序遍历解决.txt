### 解题思路
标记每层第一个进队的节点，当访问到同层第一个节点时，若其子节点非空，则说明树还会向下延伸，此时转移再记录下一层第一个节点，以此类推。
但可能会出现根节点的右子树深度远大于左子树的情况，则此时则需要转移同层第一个节点的指针，方法很简单，因为层序遍历同层节点在队列中都是相邻的，所以就是转移到队列的头节点就行。
这么做的目的是为了能保证每一个可以向下延伸的节点都得到遍历，即得到同层仍可以继续向下延伸的节点。
虽然效率可能不及dfs，但尝试新思路总不是件坏事。

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
    int maxDepth(TreeNode* root) {
 queue<TreeNode *> trees;
    if (root == NULL)
        return 0;
    trees.push(root);
    int level = 1;
    bool flag = false;
    TreeNode* firstNode = root;
    while (!trees.empty()) {
        TreeNode *mid = trees.front();
        trees.pop();
        if (mid->left != NULL && mid == firstNode) {
            flag = true;
        } else if (mid->right != NULL && mid == firstNode)
            flag = true;

        if (mid->left != NULL) {
            if (flag) {
                level++;
                firstNode = mid->left;
                flag = false;
            }
            trees.push(mid->left);
        }
        if (mid->right != NULL) {
            if (flag) {
                level++;
                firstNode = mid->right;
                flag = false;
            }
            trees.push(mid->right);
        }
//如果此节点为该层第一个节点，若其为叶子节点，为防止树其他子树有更深的层数，所以转移第一节点指针到队列头，即其其他同层
        if (mid==firstNode&&mid->right == NULL && mid->left == NULL && !trees.empty())
            firstNode = trees.front();
    }
    return level;
    }
};
```