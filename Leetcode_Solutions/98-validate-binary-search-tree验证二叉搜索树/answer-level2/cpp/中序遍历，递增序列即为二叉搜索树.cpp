### 解题思路
执行用时 :12 ms, 在所有 C++ 提交中击败了92.71%的用户
内存消耗 :
23.5 MB, 在所有 C++ 提交中击败了5.00%的用户

保存一下中序遍历的结果，然后判断是否是递增序列即可(注意空树也是二叉搜索树)
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
    void order(TreeNode* node, vector<int>& values){
        if(node==NULL) return;
        order(node->left,values);
        values.push_back(node->val);
        order(node->right,values);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> values;
        order(root,values);
        if(values.empty()) return true;
        for(vector<int>::iterator it=values.begin();it!=values.end()-1;it++){
            if(*it>=*(it+1)) return false;
        }
        return true;
    }
};
```