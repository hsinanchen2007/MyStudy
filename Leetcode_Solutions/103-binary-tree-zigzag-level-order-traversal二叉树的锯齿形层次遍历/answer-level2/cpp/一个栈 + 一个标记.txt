我看大部分的题解都是双端队列或者两个栈，不过我的想法是只用一个栈加一个 `bool` 标记。

想法：注意到栈的入栈和出栈本来就是相反的顺序，如果利用这一点，再要考虑的就只剩下 `left` 和 `right` 谁先入栈的问题了。我使用一个 `bool rev` 来标记，当它为 `true` 的时候，先入 `left`，当它为 `false` 的时候，先入 `right`。

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        bool rev = false;
        vector<vector<int>> ret;
        vector<TreeNode*> s;
        s.push_back(root);
        while (s.empty() == false) {
            auto sz = s.size();
            vector<int> rec;
            vector<TreeNode*> temp;
            if (rev)
                for (auto i = sz - 1; i < sz; --i) {
                    rec.push_back(s[i]->val);
                    if (s[i]->right != nullptr)
                        temp.push_back(s[i]->right);
                    if (s[i]->left != nullptr)
                        temp.push_back(s[i]->left);
                }
            else
                for (auto i = sz - 1; i < sz; --i) {
                    rec.push_back(s[i]->val);
                    if (s[i]->left != nullptr)
                        temp.push_back(s[i]->left);
                    if (s[i]->right != nullptr)
                        temp.push_back(s[i]->right);
                }
            s = move(temp);
            ret.push_back(move(rec));
            rev = !rev;
        }
        return ret;
    }
};
```