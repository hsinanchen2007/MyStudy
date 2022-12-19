![image.png](https://pic.leetcode-cn.com/0539ab2ef66dcf16e739c2df07666d20622141930a084a469bf1ef980a309de8-image.png)

### 解题思路
代码复杂度低，结合代码和注释很容易明白。

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
    int findVal(vector<int>& vec, int start, int val)
    {//找出vec中从start开始，值为val的元素的下标
        int len = vec.size();
        for(int idx = start; idx < len; ++idx)
            if(vec[idx] == val) return idx;
        return len; // Not found
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir)
    {//注意左右界限为是左闭右开
        if(pr - pl <= 0) return nullptr;
        //用先序遍历的第一个值做中序遍历的分界点，然后递归得到left和right
        int root_val = preorder[pl];
        TreeNode * root = new TreeNode(root_val);
        int iidx = findVal(inorder, il, root_val);
        root->left = buildTreeHelper(preorder,inorder, pl+1, pl+1+iidx-il, il, iidx);
        root->right = buildTreeHelper(preorder,inorder, pl+1+iidx-il, pr, iidx+1, ir);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return nullptr;
        return buildTreeHelper(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};
```

且稍微修改一下就是106题的答案。