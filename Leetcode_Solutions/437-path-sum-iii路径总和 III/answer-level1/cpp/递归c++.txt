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
private:
    int samenum=0;
public:
    void visit(TreeNode* root,int sum,vector<int> vec){
        if(root==NULL)return;
        else{
            if(vec.size()>0){
                int tmp=vec[vec.size()-1]+root->val;
                vec.push_back(tmp);
                if(tmp==sum)samenum++;
                for(int i=0;i<vec.size()-1;++i){
                    if(tmp-vec[i]==sum)samenum++;
                }
            }else{
                vec.push_back(root->val);
                if(root->val==sum)samenum++;
            }
            visit(root->left,sum,vec);
            visit(root->right,sum,vec);
        }
    }
    int pathSum(TreeNode* root, int sum) {
        visit(root,sum,vector<int>(0));
        return samenum;
    }
};
```