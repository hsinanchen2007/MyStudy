### 解题思路
其实就是做完正向的层次遍历，然后反转结果

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       vector<vector<int>> res;
       if (!root) return res;
       queue<TreeNode*> n, m;
       n.push(root);

       vector<int> temp;
       while (!n.empty() || !m.empty()){
           while (!n.empty()){
               temp.push_back(n.front()->val);
               if (n.front() -> left) m.push(n.front() -> left);
               if (n.front() -> right) m.push(n.front() -> right);
               n.pop();
           }
           if (!temp.empty()){
               res.push_back(temp);
               temp.clear();
           }
            while (!m.empty()){
                temp.push_back(m.front() -> val);
                if (m.front() -> left) n.push(m.front() -> left);
                if (m.front() -> right) n.push(m.front() -> right);
                m.pop();
            }
            if (!temp.empty()){
                res.push_back(temp);
                temp.clear();
            }
       } 
       reverse(res.begin(), res.end());
       return res;
    }
};
```