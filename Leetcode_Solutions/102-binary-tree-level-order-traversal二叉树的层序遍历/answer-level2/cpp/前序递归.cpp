### 解题思路
记录一下解决方法
第一次用BFS，一直在思考如何用enqueue实现，越想越昏，后来学习了[@bao-bao-ke-guai-liao](/u/bao-bao-ke-guai-liao/)大佬的解法，真的非常简洁，感谢。
主要采用递归前序遍历实现，注意用depth记录层数。

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        preorder(root, 0, ans);//前序遍历
        return ans;
    }
    void preorder(TreeNode *root,int depth, vector<vector<int>> &ans){
        //修改实参，采用引用
        if (!root) return;//无或者到达末端
        if(depth>=ans.size())ans.push_back(vector<int> {});
        //注意size和depth的数学大小关系，扩容
        ans[depth].push_back(root->val);
        preorder(root->left,depth+1,ans);
        preorder(root->right,depth+1,ans);
    }

};
```