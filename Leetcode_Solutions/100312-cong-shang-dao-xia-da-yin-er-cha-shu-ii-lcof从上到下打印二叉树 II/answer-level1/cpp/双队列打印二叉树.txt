### 解题思路
本题要求从上到下打印二叉树，很容易想到采用广度优先搜索。因为要对每一层进行区分，所以可以采用双队列的方法，每次当前层的所有子节点放入第二个队列中，以此划分层次。

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> temp1;
        queue<TreeNode*> temp2;
        temp1.push(root);
        while (!temp1.empty() || !temp2.empty()){
            vector<int> vtemp;
            if(!temp1.empty()){
                while(!temp1.empty()){
                    TreeNode* treetemp = temp1.front();
                    temp1.pop();
                    vtemp.push_back(treetemp -> val);
                    if (treetemp -> left != NULL)
                        temp2.push(treetemp -> left);
                    if (treetemp -> right != NULL)
                        temp2.push(treetemp -> right);
                }
                
            }
            else if (!temp2.empty()){
                while(!temp2.empty()){
                    TreeNode* treetemp = temp2.front();
                    temp2.pop();
                    vtemp.push_back(treetemp -> val);
                    if (treetemp -> left != NULL)
                        temp1.push(treetemp -> left);
                    if (treetemp -> right != NULL)
                        temp1.push(treetemp -> right);
                }
            }
            ans.push_back(vtemp);
        }
        return ans;
    }
};
```