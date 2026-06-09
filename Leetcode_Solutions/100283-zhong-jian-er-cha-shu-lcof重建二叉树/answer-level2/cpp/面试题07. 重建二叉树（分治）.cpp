***Talk is cheap. Show me the code.***

```cpp
class Solution {
public:
    typedef vector<int>::iterator iterator;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        umap.clear();
        for (iterator iter = inorder.begin(); iter != inorder.end(); iter++) {
            umap[*iter] = iter;
        }
        return buildTree_helper(preorder.begin(), preorder.end(),
                                inorder.begin(), inorder.end());
    }

private:
    TreeNode* buildTree_helper(iterator pbegin, iterator pend,
                               iterator ibegin, iterator iend)
    {
        if (pbegin == pend) return nullptr;
        TreeNode* node = new TreeNode(*pbegin);
        if (pend - pbegin == 1) return node;
        iterator it = umap[*pbegin];
        int len = it - ibegin;
        node->left = buildTree_helper(pbegin + 1, pbegin + 1 + len, ibegin, it);
        node->right = buildTree_helper(pbegin + 1 + len, pend, it + 1, iend);
        return node;
    }

private:
    unordered_map<int, iterator> umap;
};
```
![Xnip2020-03-11_23-56-57.jpg](https://pic.leetcode-cn.com/60a94671bb2c84fd2dfc686577830dfa5ffa7b04e20c55dbb69dc2141ac4a1fd-Xnip2020-03-11_23-56-57.jpg)
