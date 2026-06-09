### 解题思路
用动态规划的思想
1. 选择根节点：左右字节点不能再选了，可以选择左右节点的子节点（如果存在的话）。
2. 不选根节点：那就选择左右子节点（如果存在的话）

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

/**
用动态规划的思想
1. 选择根节点
2. 不选根节点
**/
class Solution {
private:
    map<TreeNode *, int> OPT;
public:

    // Map<TreeNode, Integer> memo = new HashMap<>();
    int rob(TreeNode* root) {
        // if(OPT(root) != NULL) return OPT(root);
        map<TreeNode *, int> :: iterator iter;
        iter = OPT.find(root);
        if(iter != OPT.end()){  // 查找到
            return iter->second;
        }

        if(root == NULL) return 0;

        int sr = root->val;     // 选择root节点的值
        int nsr = 0;    // 不选择root节点的值

        nsr += (rob(root->left) + rob(root->right));    // 不选择当前节点，那就选择左右子节点
        // 选择当前root，
        if(root->left != NULL){
            sr += rob(root->left->left) + rob(root->left->right);
        }
        if(root->right != NULL){
            sr += rob(root->right->left) + rob(root->right->right);
        }        
        int res = max(sr, nsr);
        // OPT.insert(root, res);
        OPT.insert(map<TreeNode *, int>::value_type(root, res));
        // enumMap.insert(map<int, CString> :: value_type(2, "Two"))
        return res;
    }
};
```