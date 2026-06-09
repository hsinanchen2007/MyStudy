### 解题思路
思路特别暴力，就是先层次遍历，得到102题的答案，然后让偶数层数组进栈，再出栈并重新赋值给偶数层数组。
击败 双100%

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){
		    return res;
	    }
        queue<TreeNode*> Q;
        TreeNode* p;
        Q.push(root);
        while(!Q.empty()){
            vector<int> a;
            int width = Q.size();
            for(int i = 0; i < width; i++){
                p = Q.front();
                a.push_back(p->val);
                Q.pop();
                if(p->left) Q.push(p->left);
                if(p->right) Q.push(p->right);
            }
            res.push_back(a);
        }

        stack<int> s1;
        for (int i = 0; i < res.size(); i++) {
            if (i % 2 != 0) {
                for (int j = 0; j < res[i].size(); j++) {
                    s1.push(res[i][j]);
                }
                for (int j = 0; j < res[i].size(); j++) {
                    res[i][j] = s1.top();
                    s1.pop();
                }
            }
        }
    return res;        
    }
};
```