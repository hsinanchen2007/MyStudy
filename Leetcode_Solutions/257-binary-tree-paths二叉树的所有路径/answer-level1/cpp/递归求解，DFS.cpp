
//本题主要注意需要将int值转换为string，int值有可能是负数，所以记得要进行判断，此外还要注意->的输出格式的问题
```
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL) return res;
        DFS(root);
        return res;
    }

    string intToStirng(int x){
        bool flag = false;
        if(x<0){
            flag = true;
            x = -x;
        }
        string ans;
        while(x!=0){
            ans+=x%10+'0';
            x = x/10;
        }
        if(flag) ans+='-';
        reverse(ans.begin(),ans.end());
        return ans;
    }

    vector<string> res;
    vector<string> temp;
    void DFS(TreeNode* root){
        if(root->left==NULL&&root->right==NULL){
            temp.push_back(intToStirng(root->val));
            string ans="";
            for(int i=0;i<temp.size();i++){
                ans+=temp[i];
                if(i!=temp.size()-1) ans+="->";
            }
            res.push_back(ans);
            temp.pop_back(); 
        }
        temp.push_back(intToStirng(root->val));
        if(root->left!=NULL) DFS(root->left);
        if(root->right!=NULL) DFS(root->right);
        temp.pop_back();
    }
};
```
