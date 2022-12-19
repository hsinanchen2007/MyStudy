思路：
1. 每一层通过队列保存节点
2. while循环遍历队列中的所有节点，for循环遍历每一层的节点队列，保存到每一层的数组。同时将下一层节点push到队列


```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> lev; // 每一层的节点val值数组，即每层的答案
        queue<TreeNode*> q; // 每一层的节点数队列
        if (root == nullptr) {
            return ans;
        } 
        q.push(root);
        while(!q.empty()) {
            int num = q.size();
            TreeNode* tmp;
            // 对每一层的节点队列进行迭代遍历，取出val保存到数组，将下一层的节点push到队列
            for (int i = 0; i < num; i++) {
                tmp = q.front();
                lev.push_back(tmp -> val );
                if (tmp -> left != nullptr) {
                    q.push(tmp -> left);
                }
                if (tmp -> right != nullptr) {
                    q.push(tmp -> right);
                }
                q.pop();
            }
            ans.push_back(lev);
            lev.clear();
        }
        return ans;
    }
};

```
