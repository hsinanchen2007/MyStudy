这个题目的例子有点搞混人，其实就是要求最深的叶子节点的最近公共父节点。如果最深的叶子节点没有兄弟，那么公共父节点就是它自己，否则返回它的父节点。
思路：我们可以从某个节点A为根节点的子树思考，先求它左、右节点的高度和最近公共父节点。
1、如果左、右节点的高度相同，那么公共父节点就是A。
2、如果左节点的高度比右节点大，最深的叶子节点的最近公共父节点肯定是左节点返回的结果里面。
3、如果右节点的高度比左节点大，最深的叶子节点的最近公共父节点肯定是右节点返回的结果里面。
4、上面的每一步，都会导致高度加1.
5、如果是空节点，那么高度为0.公共父节点为NULL。

```
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
    
    typedef pair<int, TreeNode*> Tr;

    Tr leavesDFS(TreeNode* root) {
        if (root == NULL) {
            return Tr(0, NULL);
        }
        auto l = leavesDFS(root->left);
        auto r = leavesDFS(root->right);
        if (l.first == r.first) {
            return Tr(l.first + 1, root);
        } else if (l.first > r.first) {
            return Tr(l.first + 1, l.second);
        } else {
            return Tr(r.first + 1, r.second);
        }
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return leavesDFS(root).second;
    }

};
```