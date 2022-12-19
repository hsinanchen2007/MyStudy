### 解题思路
此处撰写解题思路

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

        vector<vector<int>> result;
        queue<TreeNode *> s;
        if(!root) {
            return result;
        }

        int curNum = 1;
        int nextNum = 0;
        s.push(root);

        vector<int> *curVec = NULL;
        while(!s.empty()){
            TreeNode *node = s.front();
            s.pop();
            if(curVec == NULL) {
                curVec = new vector<int>;
                
            }
            curVec->push_back(node->val);

            if(node->left){
                s.push(node->left);
                nextNum++;
            }

            if(node->right){
                s.push(node->right);
                nextNum++;
            }
            curNum--;
            if(curNum == 0) {
                curNum = nextNum;
                nextNum = 0;
                result.push_back(*curVec);
                curVec = NULL;
            }


        }
        return result;
        
    }
};
```