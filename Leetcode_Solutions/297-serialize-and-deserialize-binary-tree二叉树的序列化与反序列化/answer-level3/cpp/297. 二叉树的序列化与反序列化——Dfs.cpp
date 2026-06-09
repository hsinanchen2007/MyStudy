题意关键在于可以自主决定序列化的内容，反序列化时只需要根据自己的规则即可。
本体最简便的方法是使用Dfs，序列化和反序列采用相同的遍历顺序即可。
```
class Codec {
    private:
    void Dfs(TreeNode* root, string &res)
    {
        if(root==nullptr){
            res+="null,";
            return;
        }
        res += std::to_string(root->val) +",";
        Dfs(root->left,res);
        Dfs(root->right,res);
    }
    void DeDfs(TreeNode* &root, string &s, int &idx)
    {
        if(idx>=s.size()){
            root=nullptr;
            return;
        }
        string::size_type i = s.find(",",idx);
        if(i==s.npos){
            idx=s.size();
            return;
        }
        string ss=s.substr(idx,i-idx);
        idx=i+1;
        if(ss.compare("null")==0){
            root=nullptr;
            return;
        }
        istringstream tmp(ss);
        int val;
        tmp>>val;
        root=new TreeNode();
        root->val=val;
        DeDfs(root->left,s,idx);
        DeDfs(root->right,s,idx);
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        Dfs(root,res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root=nullptr;
        int idx=0;
        DeDfs(root,data,idx);
        return root;
    }
};
```
