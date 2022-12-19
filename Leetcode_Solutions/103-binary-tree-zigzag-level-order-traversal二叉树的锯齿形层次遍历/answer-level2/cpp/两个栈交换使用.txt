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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool flag=false;
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*> st1,st2;
        st2.push(root);
        while((!st1.empty())||(!st2.empty())){
            vector<int> v;
            TreeNode* temp;
            int size;
            if(flag==false){
                flag=true;
                size=st2.size();
                for(int i=0;i<size;++i){
                    temp=st2.top();
                    st2.pop();
                    v.push_back(temp->val);
                    if(temp->left){
                        st1.push(temp->left);
                    }
                    if(temp->right){
                        st1.push(temp->right);
                    }
                }
            }
            else if(flag=true){
                flag=false;
                size=st1.size();
                for(int i=0;i<size;++i){
                    temp=st1.top();
                    st1.pop();
                    v.push_back(temp->val);
                    if(temp->right){
                        st2.push(temp->right);
                    }
                    if(temp->left){
                        st2.push(temp->left);
                    }
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};
```
