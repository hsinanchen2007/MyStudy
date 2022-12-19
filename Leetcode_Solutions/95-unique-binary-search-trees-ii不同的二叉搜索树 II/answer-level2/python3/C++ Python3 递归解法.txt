### 解题思路
给定一个整数n，要返回所有可能的二叉搜索树，可以依次取i in [0:n]作为根节点，小于i的所有元素构成i的左子树，大于i的所有元素构成i的右子树。


### Python3 版本

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        def generateTrees(start:int, end:int) -> List[TreeNode]:
            if start > end:
                return [None]
            allTree = []
            for i in range(start, end+1):
                left_trees = generateTrees(start, i-1)
                right_trees = generateTrees(i+1, end)
                for left_tree in left_trees:
                    for right_tree in right_trees:
                        root = TreeNode(i)
                        root.left = left_tree
                        root.right = right_tree
                        allTree.append(root)
            return allTree

        if n==0:
            return []
        return generateTrees(1, n)
```

### C++版本

```c++
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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return {};
        return generateTrees(1, n);
    }
private:
    vector<TreeNode*> generateTrees(int start, int end)
    {
        vector<TreeNode*> allTree;
        if(start > end)
        {
            allTree.push_back(nullptr);
            return allTree;
        }

        for(int i = start; i <= end; i++)
        {//选择一个作为root
            vector<TreeNode*> left_sub_tree = generateTrees(start, i-1);//所有的左子树
            vector<TreeNode*> right_sub_tree = generateTrees(i+1, end);//所有的右子树
            for(TreeNode* left_tree : left_sub_tree){//左子树与右子树的所有组合（笛卡尔积）
                for(TreeNode* right_tree: right_sub_tree) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left_tree;
                    root->right = right_tree;
                    allTree.push_back(root);
                }
            }
        }
        return allTree;
    }
};
```