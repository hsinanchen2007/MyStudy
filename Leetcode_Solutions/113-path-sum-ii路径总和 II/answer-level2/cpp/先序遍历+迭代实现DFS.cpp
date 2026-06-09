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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        stack<pair<TreeNode*, int>> mystack;
        vector<int> tmpvec;
        vector<vector<int>> result;
        int tmpsum=0;
        if(root==NULL){
            return result;
        }
        mystack.push(make_pair(root,0));
        
        while(!mystack.empty()){
            TreeNode* curr;
            curr = mystack.top().first;
            if(mystack.top().second){// 若为1则说明已经访问过
                mystack.pop();
                tmpsum -=tmpvec[size(tmpvec)-1];//在sum里面减去这个回退路上曾经加过的值
                tmpvec.pop_back();
                continue;
            }
            tmpsum += curr->val;
            tmpvec.push_back(curr->val);
            mystack.top().second = 1;//设置已经访问
            if(curr->right!=NULL){//先序遍历
                mystack.push(make_pair(curr->right,0));
            }
            if(curr->left!=NULL){
                mystack.push(make_pair(curr->left,0));
            }
            if(curr->right==NULL && curr->left==NULL && tmpsum == sum){
                //叶子节点且符合要求
                result.push_back(tmpvec);
            }
        }
        return result;
    }
};