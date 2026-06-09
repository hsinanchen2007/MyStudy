### 解题思路
#### 步骤一：中序遍历二叉树
根据二叉搜索树性质可知，对于二叉搜索树中的每一个结点，左子树中的值 < 该结点值 < 右子树中的值，所以二叉搜索树的中序遍历的结果就是一个升序序列；
在本题中，使用递归算法遍历两个二叉搜索树，得到两个升序序列；
#### 步骤二：双指针查找
建立两个指针，指针1从第一个序列的最小元素开始遍历，指针2从第二个序列的最大元素开始遍历；对两个指针指向元素进行求和，如果两元素之和与目标值相等，返回true；如果两元素之和小于目标值，指针1后移；如果两元素之和大于目标值，指针2前移；直到遍历完其中一个序列，如果最后没有找到，返回false。
#### 运行结果
看代码就可以很好的理解此过程，此代码在执行时间上击败了100%的C++用户。
![lihai.JPG](https://pic.leetcode-cn.com/d7b070771085e6f7c13fb2f7a8972d756bccdff629152d03290305f2491e6581-lihai.JPG)

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
private:
    void inOrder(TreeNode* root, vector<int> &ans) {
        if (root == NULL) { return ; }
        inOrder(root->left, ans);
        ans.push_back(root->val);
        inOrder(root->right, ans);
    }
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int> tree1;
        vector<int> tree2;
        inOrder(root1, tree1);
        inOrder(root2, tree2);
        int l1 = tree1.size(), l2 = tree2.size();
        int i = 0, j = l2 - 1;
        while (i < l1 && j >= 0) {
            int add = tree1[i] + tree2[j];
            if (add > target) {
                j--;
            }
            else if (add < target) {
                i++;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
```