### 解题思路
此处撰写解题思路

### 代码
```
代码块
```

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
    int deepestLeavesSum(TreeNode* root) {
        searchTree(root,0);
        int depth = INT_MIN;
        auto it = hash.end();
        it--;//深度最大在最后面
        return it->second;
    }
//深度优先遍历 DFS
    void searchTree(TreeNode* root,int depth){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            hash[depth] += root->val;//深度为depth得累加和
        }
        if(root->left) searchTree(root->left,depth+1);
        if(root->right) searchTree(root->right,depth+1);
    }

private:
    map<int,int> hash;//key为深度  value为所有深度相同结点的val得和
};
```