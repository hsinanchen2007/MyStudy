### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/23255986a273587434b7a4daac95e3a91bbbc7a77ef120a9d531c5681576b7a6-image.png)

显示“->”是真的烦人，使用了一个bool flag

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
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL){
            return res;
        }
        string str;
        process(root,res,str);
        return res;

    }

private:
    bool flag = true;
    void process(TreeNode* root,vector<string>& res,string str){
        if(flag){
             str += to_string(root->val);
             flag = false;
        }
        else{
             str += "->"+to_string(root->val);
        }
        if(root->left ==NULL && root->right == NULL){
            res.push_back(str);
            return;
        }
        if(root->left){
            process(root->left,res,str);
        }
        if(root->right){
            process(root->right,res,str);
        }

    }

};
```