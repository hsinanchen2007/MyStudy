为了写代码方便，需要把-整合一下，我定义的是把---定义成_$3_，这样字符串操作比较好find。
然后普普通通dfs即可。
```
class Solution {
public: 
    TreeNode* dfs(string  S,int level){
        string f = "_$"+to_string(level)+"_";
       // cout << level << endl;
        int pos = S.find(f);
        if(pos == -1){ //说明返回，只有这是叶子节点
            TreeNode* root = new TreeNode(atoi(S.c_str()));
            return root;
        }
        TreeNode* root = new TreeNode(atoi(S.substr(0,pos).c_str()));
        S.erase(0,pos+f.size());
        int pos2 = S.find(f);
        if(pos2 == -1){
            root->left = dfs(S,level+1);
        }
        else{
            root->left = dfs(S.substr(0,pos2),level+1);
            root->right = dfs(S.substr(pos2+f.size(),S.size()-pos2-f.size()),level+1);
        }
        return root;
    }
    TreeNode* recoverFromPreorder(string S) {
        string snow = "";
        int pos = 0;
        while(pos < S.size()){
            if(S[pos]!= '-')snow+=S[pos++];
            else{
                int postemp = 0;
                while(pos<S.size()&&S[pos]=='-')
                    pos++,postemp++;
                string temp = "_$"+to_string(postemp)+"_";
                snow+=temp;
            }
        }
        TreeNode* root = dfs(snow,1);
        return root;
    }
};
```
