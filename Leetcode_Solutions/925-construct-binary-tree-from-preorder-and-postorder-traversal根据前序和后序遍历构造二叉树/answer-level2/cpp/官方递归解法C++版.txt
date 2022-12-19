```
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int length = post.size();
        if(length==0) return NULL;
        TreeNode* root = new TreeNode(pre[0]);
        if(length==1) return root;
        else{
            int L=0;
            for(int i=0; i<post.size();++i){
                if(post[i]==pre[1]){
                    L = i+1;
                }
            }
            
            vector<int> leftPre(pre.begin()+1, pre.begin()+L+1);
            vector<int> rightPre(pre.begin()+L+1, pre.end());
            vector<int> leftPost(post.begin(), post.begin()+L);
            vector<int> rightPost(post.begin()+L, post.end()-1);
            root->left = constructFromPrePost(leftPre, leftPost);
            root->right = constructFromPrePost(rightPre, rightPost);
            return root;
        }
    }
};
```
