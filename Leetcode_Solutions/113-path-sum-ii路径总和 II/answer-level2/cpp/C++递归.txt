### 解题思路
自我记录一下笔记，首先这个题用递归比较整洁简单。
第一次提交用了**值传递数组**的方式，虽然这种方式比较省事，每次递归回到上一层的时候，数组内的值就是到当前节点为止的路径节点，但是由于每次递归是值拷贝，所以内存消耗比较大。
第二次提交用了**引用传递数组**，每次回到上一层递归的时候就需要将上一个的节点值从数组里弹出，这样才能保持数组记录的是到当前节点的路径值，避免了值拷贝的内存消耗，提升了不少效率。

![202042-152332.jpg](https://pic.leetcode-cn.com/007d9c11176e2fe2d880d00cc7455d29ae1f8593b1cebe0ddb13d249393b15a7-202042-152332.jpg)



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
    vector<vector<int>> retVec;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> vec;
        findPathSum(root, sum, vec);
        return retVec;
    }
    //如果是引用方式传入数组则需要在将这个节点左右子节点遍历完成后弹出该节点的值
    //如果是以值传递方式传入数组则不需要
    void findPathSum(TreeNode* root, int sum, vector<int>& vec)
    {
        if(root == nullptr) return;
        sum -= root->val;
        vec.push_back(root->val);
        if(root->right == nullptr && root->left == nullptr && sum == 0)
        {
            retVec.push_back(vec);
            //return;
        }
        findPathSum(root->left, sum, vec);
        findPathSum(root->right, sum, vec);
        vec.pop_back();
    }
};
```
```