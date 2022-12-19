
使用deque的 
front(), back();
push_front(), push_back();
pop_front(), pop_back().
前取后放，后取前放。


```
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        deque<TreeNode*> que;
        que.push_back(root);
        bool zigzag = true;
        TreeNode* tmp;
        while (!que.empty()) {
            int Size = que.size();
            vector<int> tmp_vec;
            while (Size) { 
                if (zigzag) { % 前取后放
                    tmp = que.front();
                    que.pop_front();
                    if (tmp->left) que.push_back(tmp->left); % 下一层顺序存放至尾
                    if (tmp->right) que.push_back(tmp->right);                
                } else { % 后取前放
                    tmp = que.back();
                    que.pop_back();
                    if (tmp->right) que.push_front(tmp->right); % 下一层逆序存放至首
                    if (tmp->left) que.push_front(tmp->left);
                }
                tmp_vec.push_back(tmp->val);
                --Size;
            }
            zigzag = !zigzag;
            ans.push_back(tmp_vec);
        }
        return ans;
    }
};
```