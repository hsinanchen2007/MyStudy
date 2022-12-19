### 解题思路
此处撰写解题思路

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
     unordered_set<int> hash;
    bool findTarget(TreeNode* root, int k) {
       bianli(root);
        //遍历set，判断当前的k - value 是否也在set中。若存在，返回true
        for(auto it = hash.begin();it != hash.end();it++){
            cout<<*it<<endl;

            if(hash.count(k-*it) != 0 && *it != (k-*it)){
                return true;
            }
        }
        return false;
    
    }
    //遍历二叉树，i将结点insert到set中
    void bianli(TreeNode* root){
        if(!root){
            return;
        }
        if(root->left) bianli(root->left);
        hash.insert(root->val);
        if(root->right) bianli(root->right);
    }

};
```