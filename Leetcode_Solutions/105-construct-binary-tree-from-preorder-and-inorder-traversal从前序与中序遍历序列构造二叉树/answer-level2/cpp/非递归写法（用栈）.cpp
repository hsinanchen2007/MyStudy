### 解题思路
用栈来存节点，用set来存已经出现过的节点，当中序的节点在先序中出现过时发起回溯。
插入规则：前一个节点一样，则插入右节点，因为只有父与右孩子在两种遍历中先后顺序一样。

### 代码

```cpp
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        stack<TreeNode*> stk;
        set<int> seen;
        int i = 1, j = 0;
        TreeNode* root = new TreeNode(preorder[0]);
        stk.push(root);
        seen.insert(preorder[0]);
        if (preorder[0] == inorder[0]) j++;

        while (i < preorder.size()) {
            TreeNode* p = stk.top();
            if (preorder[i] == inorder[j] || seen.find(inorder[j]) == seen.end()) { // 元素相同则插入后一起移动， 元素不同则看是否在先序出现过，如果没出现过就插入
                if (j > 0 && inorder[j - 1] == stk.top()->val) {
                    p->right = new TreeNode(preorder[i]);
                    stk.push(p->right);
                } else {
                    p->left = new TreeNode(preorder[i]);
                    stk.push(p->left);
                }
                if (seen.find(inorder[j]) != seen.end()) j++; // 出现过
                seen.insert(preorder[i]);
                i++;
            } else { // 元素不同且先序出现过，说明该回溯了
                while (stk.top()->val != inorder[j]) stk.pop();
                j++;
            }
        }
        
        return root;
    }
};
```