### 解题思路
二叉搜索树的判断有两种判断方式：中根遍历呈单调递增特性，使用遍历，传入上限和下限值。
这里构造所有的二叉搜索树，利用递归的方式求解。
对于根节点而言，low~high都可以成为根节点，
如果k为根节点，那么它的左子树就只能在low - 1里面产生；右字数只能在high + 1里面产生；
但是递归调用的时候，返回的并不是某一个节点，而是一个以根节点为根的集合；

本题关键点应该在于如果将左子树集合和右字数集合重合起来。

这里的做法是先判断左子树集合，如果左子树集合为空，就先给它赋一个NULL，方便后面的组合；
最后注意每次往ans里面插入的时候，都需要新建一个节点，这个是对C++语言的指针的理解。

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
vector<TreeNode*> GetBST(int low, int high)
{
    vector<TreeNode*> ans;
    for (int i = low; i <= high; i++) {
        vector<TreeNode*> leftTreeVec;
        vector<TreeNode*> rightTreeVec;
        if (i > low) {
            leftTreeVec = GetBST(low, i - 1);
        }
        if (i < high) {
            rightTreeVec = GetBST(i + 1, high);
        }
        if (leftTreeVec.empty()) {
            leftTreeVec.push_back(NULL);
        }

        for (auto leftItem : leftTreeVec) {
            if (rightTreeVec.empty()) {
				TreeNode* currentNode = new TreeNode(i);
				currentNode->left = leftItem;
                ans.push_back(currentNode);
            }
            for (auto rightItem : rightTreeVec) {
				TreeNode* currentNode = new TreeNode(i);
                currentNode->left =  leftItem;
				currentNode->right = rightItem;
                ans.push_back(currentNode);
            }
        }
    }
        return ans;
}
vector<TreeNode*> generateTrees(int n) {
     return GetBST(1, n);
}
};
```