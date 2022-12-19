## 思路：递归
关键在与正确定位左右子树范围。

### 代码

```cpp
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int> &preorder, int pstart, int pend, vector<int> &inorder, int istart, int iend) {
        if (pend < pstart) return nullptr;
        int val = preorder[pstart];
        TreeNode* root = new TreeNode(val);
        auto it = find(inorder.begin() + istart, inorder.begin() + (iend + 1), val);//注意在[istart, iend]范围内搜索
        int lenLeft = it - find(inorder.begin() + istart, inorder.begin() + (iend + 1), inorder[istart]);
        root->left = helper(preorder, pstart + 1, pstart + lenLeft, inorder, istart, istart + lenLeft - 1);
        root->right = helper(preorder, pstart + lenLeft + 1, pend, inorder, istart + lenLeft + 1, iend);
        return root;
    }
};
```

### 另一种写法
修改求根节点索引。

```c++
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int> &preorder, int pstart, int pend, vector<int> &inorder, int istart, int iend) {
        if (pend < pstart) return nullptr;
        int val = preorder[pstart];
        TreeNode* root = new TreeNode(val);
        auto it = find(inorder.begin() + istart, inorder.begin() + (iend + 1), val);
        int index = it - inorder.begin();        
        int lenLeft = index - istart;
        root->left = helper(preorder, pstart + 1, pstart + lenLeft, inorder, istart, index - 1);
        root->right = helper(preorder, pstart + lenLeft + 1, pend, inorder, index + 1, iend);
        return root;
    }
};
```
