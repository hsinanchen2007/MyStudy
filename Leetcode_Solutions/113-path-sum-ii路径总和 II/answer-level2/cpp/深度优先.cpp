### 解题思路
找所有路径，典型的深度优先， 
注意题中的路径是指从根节点到没有子节点的叶子结点为一条路径。
使用temp数组暂存数据。

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
    // 执行用时 :8 ms, 在所有 C++ 提交中击败了94.54% 的用户
    // 内存消耗 :30.3 MB, 在所有 C++ 提交中击败了34.72%的用户
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        // vector<vector<int>> res;
        if(!root) return res;
        vector<int> temp;//中间变量
        pathSumCore(root, sum, temp);
        return res;
    }

    void pathSumCore(TreeNode* root, int sum, vector<int> temp){
        if(!root->left&&!root->right&&sum==root->val){//若为叶节点，且值等于sum 。
            temp.push_back(sum);
            res.push_back(temp);
            return;
        }
        if(!root->left&&!root->right&&sum!=root->val) {
            return;
        }
        else{
            temp.push_back(root->val);//先把数暂存起来。
            if(root->left) pathSumCore(root->left, sum-root->val, temp);//有左节点就递归左节点。
            if(root->right) pathSumCore(root->right, sum-root->val, temp);//有右节点就递归右节点。
            temp.pop_back();//已经遍历过或者值不相等的就要弹出来。

        }
    }


    vector<vector<int>> res;//使用全局变量快一点。
};
```