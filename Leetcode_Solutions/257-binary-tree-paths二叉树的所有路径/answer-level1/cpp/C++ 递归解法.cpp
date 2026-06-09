思路比较简单：主要的想法就是得到所有子树的路径，然后和根组合在一起。
1. 如果是根节点，就`root->val`加入`vector<string>`并返回.
2. 如果不是根结点，那就对左右子树递归，得到以他们为根的路径。 

```
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) { //递归
        vector<string> re,leftPath,rightPath;
        string path;
        if(root == nullptr) return re;
        path = to_string(root->val);
        //边界检测
        if(root->left == nullptr && root->right == nullptr){
            re.push_back(path);
            return re;
        }
        //不是叶节点
        if(root->left != nullptr) leftPath = binaryTreePaths(root->left);
        if(root->right != nullptr) rightPath = binaryTreePaths(root->right);
        for(auto le : leftPath){
            string tmp = path + "->" + le;
            re.push_back(tmp);
        }
        for(auto ri : rightPath){
            string tmp = path + "->" + ri;
            re.(tmp);
        }
        return re;
    }
};
```
