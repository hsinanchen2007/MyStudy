就二叉树的层次遍历呗
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
class Codec {
public:

    // Encodes a tree to a single string.
    TreeNode* r=NULL;
    vector<string> res;
    string serialize(TreeNode* root) {
        r=root;
        if(!root){
            res.push_back("null");
            return "null";
        }
        queue<TreeNode*> q;TreeNode* now;
        res.push_back(to_string(root->val));
        q.push(root);
        while(!q.empty()){
            now=q.front();q.pop();
            if(now->left){
                res.push_back(to_string(now->left->val));
                q.push(now->left);
            }
            else{
                res.push_back("null");
            }
            if(now->right){
                res.push_back(to_string(now->right->val));
                q.push(now->right);
            }
            else{
                res.push_back("null");
            }
        }
        int a=res.size()-1;
        while(a>=0){
            if(res[a]!="null")break;
            res.pop_back();a--;
        }
        return "null";
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(res[0]=="null")return r;
        r=new TreeNode(stoi(res[0]));
        int p=1,n=res.size();
        queue<TreeNode*> q;TreeNode* now;
        q.push(r);
        while(!q.empty()&&p<n){
            now=q.front();
            q.pop();
            if(res[p]!="null"){
                now->left=new TreeNode(stoi(res[p]));
                q.push(now->left);
            }
            p++;
            if(p>=n)break;
            if(res[p]!="null"){
                now->right=new TreeNode(stoi(res[p]));
                q.push(now->right);
            }
            p++;
        }
        return r;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```
