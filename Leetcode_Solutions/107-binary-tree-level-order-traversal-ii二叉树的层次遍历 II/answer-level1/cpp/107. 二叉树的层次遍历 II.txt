

层次遍历，再逆序，解法不够优美

```
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
        if(root == NULL){
            return {};
        }
        queue<pair<TreeNode*, int>> myque;
        vector<vector<int>> myres;
        vector<int> tmp;
        myque.push(make_pair(root, 0));
        while(!myque.empty()){
            TreeNode* myNode = myque.front().first;
            int level = myque.front().second;
            if(myres.size() != level){
                myres.push_back(tmp);
                tmp={};
            }
            tmp.push_back(myNode->val);
            myque.pop();

            if(myNode->left != NULL){
                myque.push(make_pair(myNode->left, level+1));
            }
            if(myNode->right != NULL){
                myque.push(make_pair(myNode->right, level+1));
            }

        }
        myres.push_back(tmp);
        reverse(myres.begin(),myres.end());
        return myres;
    }
};
```
