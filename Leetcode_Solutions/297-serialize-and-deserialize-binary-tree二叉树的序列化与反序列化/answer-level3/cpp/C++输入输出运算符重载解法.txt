
使用C++的输入输出运算符前序遍历序列化和反序列化实现。


```
ostream& operator<<(ostream& os,const TreeNode* root){
     if(NULL==root) return os << "# ";
     return os << root->val << ' ' << root->left << root->right;
 }
 istream& operator>>(istream& is,TreeNode*& root){
     string val;
     is >> val;
     if(val == "#") root = nullptr;
     else{
        root = new TreeNode(stoi(val));
        is >> root->left >> root->right;
     }     
     return is;
 }
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        out << root;
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root;
        istringstream in(data); 
        in >> root;
        return root;
    }
};
```