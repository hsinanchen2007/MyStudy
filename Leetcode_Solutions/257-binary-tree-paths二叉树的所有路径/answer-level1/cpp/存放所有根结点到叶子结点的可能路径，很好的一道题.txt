### 解题思路
本题 稀里糊涂就写出来了。
主要采用先序遍历，若当前结点有孩子，那么加入path，否则，是叶子结点，也加入到path，将成功的path加入到result中，此时继续向左向右递归，注意
返回上一层，需要将这一层root删除，递归边界是NULL,实际上改为叶子结点也可以。


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
    string path;
    vector<string> res;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        backtrack(root);
        return res;
        
        


    }
    void backtrack(TreeNode* root){
        if(!root) return;
        int len = path.size();
        if(root->left||root->right){
           path += (path.empty() ? "" : "->")+to_string(root->val);
        }else{
            path +=(path.empty()?"":"->")+to_string(root->val);
            res.push_back(path);
            path.erase(path.begin()+len,path.end());
        }
        backtrack(root->left);
        backtrack(root->right);
        path.erase(path.begin()+len,path.end());
        return;

        
    }
};
```