## 思路
通过重新构建新序列进行递归。
### 代码
```c++
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (!postorder.empty()) {            
            int val = postorder.back();
            TreeNode *root = new TreeNode(val);
            if (postorder.size() == 1) return root;
            auto it = find(inorder.begin(), inorder.end(), val);
            int index = it - inorder.begin();            
            vector<int> inLeft(inorder.begin(), inorder.begin() + index);
            vector<int> inRight(inorder.begin() + index + 1, inorder.end());                                                              vector<int> posLeft(postorder.begin(), postorder.begin() + inLeft.size());
            vector<int> posRight(postorder.begin() + inLeft.size(), postorder.end() - 1);
            root->left = buildTree(inLeft, posLeft);
            root->right = buildTree(inRight, posRight);
            return root;
        }
        return nullptr;
    }
};
```
### 另一种写法
通过下标范围指定新序列。
```c++
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode* helper(vector<int> &inorder, int istart, int iend, vector<int> &postorder, int pstart, int pend) {
        if (istart > iend) return nullptr;        
        TreeNode *root = new TreeNode(postorder[pend]);
        auto it = find(inorder.begin() + istart, inorder.begin() + iend + 1, root->val);
        int index = it - inorder.begin();
        int numLeft = index - istart;//左子树元素个数
        root->left = helper(inorder, istart, index - 1, postorder, pstart, pstart + numLeft - 1);//去除中序序列根节点
        root->right = helper(inorder, index + 1, iend, postorder, pstart + numLeft, pend - 1);//去除后序序列最后一个元素
        return root;
    }
};
```


