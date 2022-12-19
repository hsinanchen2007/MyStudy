### 解题思路
遇到的坑：
1. 边界划定；从分两半开始（根节点为界，中序遍历分为左子树和右子树），之后若是求左子树则左边界不变，求右子树则右边界不变。
2. 建议使用全局变量（private里整一个就行），而非引用传值。因为传着容易晕。
3. 需要学一下哈希表，很快

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pb = 0;
        int pe = inorder.size();
        int ptr_rt = 0;
        return buildTree_core(preorder, inorder, pb, pe, ptr_rt);
    }
    int findx(int a, vector<int>& vec) {
        for (int i=0; i<vec.size(); i++) {
            if (vec[i] == a)
                return i;
        }
        return -1;
    }    
    TreeNode* buildTree_core(vector<int>& preorder, vector<int>& inorder, int pb, int pe, int & ptr_rt) {
        if (pb == pe)
            return NULL;
        TreeNode* rt = new TreeNode(preorder.at(ptr_rt));
        ptr_rt++;
        rt->left = buildTree_core(preorder, inorder, pb, findx(rt->val, inorder), ptr_rt);
        rt->right = buildTree_core(preorder, inorder, findx(rt->val, inorder) + 1, pe, ptr_rt);
        return rt;
    }
};
```