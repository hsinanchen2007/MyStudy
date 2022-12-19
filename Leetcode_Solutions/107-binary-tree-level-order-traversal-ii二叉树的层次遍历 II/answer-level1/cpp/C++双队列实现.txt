### 解题思路
该题目涉及到要区分树的不同层级，使用双队列实现比较简单，C++实现，执行时间4ms

### 代码

# ```cpp
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
        queue<TreeNode*> queFather;
        queue<TreeNode*> queSon;
        vector<vector<int>> result;
        if(root == nullptr){
            return result;
        }
        TreeNode* currentRoot = root;
        queFather.push(currentRoot);
        while(!queFather.empty()){
            vector<int> curVec;
            while(!queFather.empty()){
                if(queFather.front()){
                    if(queFather.front()->left){
                        queSon.push(queFather.front()->left);
                    }
                    if(queFather.front()->right){
                        queSon.push(queFather.front()->right);
                    }
                }
                curVec.push_back(queFather.front()->val);
                queFather.pop();
            }
            queFather.swap(queSon);
            result.push_back(curVec);
        }
        vector<vector<int>> resultNol;
        for(size_t index = 0;index < result.size();index++){
            resultNol.push_back(result[result.size() - index - 1]);
        }
        return resultNol;
    }
};
```