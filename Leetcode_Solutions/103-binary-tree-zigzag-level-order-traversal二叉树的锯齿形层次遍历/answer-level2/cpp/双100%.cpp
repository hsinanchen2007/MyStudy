执行结果：
通过
显示详情
执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
11.5 MB
, 在所有 C++ 提交中击败了
100.00%
的用户

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        queue<TreeNode*> que;
        stack<int> sta;
        que.push(root);
        bool bTwo = false;
        vector<int> tv;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp;
                temp = que.front();
                que.pop();
                if (temp->left != NULL) {
                    que.push(temp->left);
                }
                if (temp->right != NULL) {
                    que.push(temp->right);
                }
                if (bTwo) {
                    sta.push(temp->val);
                } else {
                    tv.push_back(temp->val);
                }
            }
            bTwo = !bTwo;
            if (!sta.empty()) {
                vector<int> tv;
                while (!sta.empty()) {
                    tv.push_back(sta.top());
                    sta.pop();
                }
                res.push_back(tv);
                tv.clear();
            } else {
                res.push_back(tv);
                tv.clear();
            }
        }
        return res;
    }
};



