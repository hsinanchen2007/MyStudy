### 解题思路
1.根据搜索二叉树的性质，中序遍历即二叉树中所有元素的顺序排列。
2.再根据中序遍历生成的数组查找众数。

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
    vector<int> vec;
    vector<int> result;
    int max = 0;
    int cur = 0;
    vector<int> findMode(TreeNode* root) {
    LDR(root);
    if(vec.size() == 1){
        result.push_back(vec[0]);
    }
    for(int i = 1; i < vec.size(); i++){
        if(vec[i] == vec[i-1]){
            cur++;
        }
        else{
            cur = 0;
        }
        if(cur == max){
            if(i == 1 && cur ==0){
                result.push_back(vec[0]);
            }
            result.push_back(vec[i]);
        }
        else if(cur > max){
            result.clear();
            max = cur;
            result.push_back(vec[i]);
        }
    }
    return result;
}

void LDR(TreeNode* root){
    if(!root){
        return;
    }
    LDR(root->left);
    vec.push_back(root->val);
    LDR(root->right);
}
};
```