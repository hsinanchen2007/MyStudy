### 解题思路
深度优先搜索的典型应用。
1、结束条件：左右子树都为空，将当前从根节点到叶子节点的所有值入栈。
2、左子树不为空，继续遍历；右子树不为空继续遍历。
3、注意点：每次遍历都有以当前sum*10。

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
    vector<int> res;
public:
    void DFS(TreeNode* root, int sum){
        sum += root->val;
        if(!root->left && !root->right){
            res.push_back(sum);
            return;
        }
        if(root->left){
            DFS(root->left, sum*10);
        }
        if(root->right){
            DFS(root->right, sum*10);
        }
    }
    int sumNumbers(TreeNode* root) {
        if(!root){
            return 0;
        }
        DFS(root, 0);
        int sum = 0;
        for(auto i: res){
            sum += i;
        }
        return sum;
    }
};
```