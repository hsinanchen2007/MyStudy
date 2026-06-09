速度很辣鸡，反正能过（
```
class Codec {
public:
    string int2str(int a) {
        string str="";
        if(a==0)return string("0");
        while(a) {
            char c=a%10+'0';
            str=c+str;
            a/=10;
        }
        return str;
    }

    int str2int(string str,int &i) {
        int res=0;
        while(str[i]!='#') {
            res*=10;
            res+=str[i]-'0';
            i++;
        }
        i++;
        return res;
    }

    void preorder(TreeNode *node,string &str) {
        if(!node)return;
        str+=int2str(node->val);
        str+='#';
        if(node->left)preorder(node->left,str);
        if(node->right)preorder(node->right,str);
    }

    void BST_insert(TreeNode *node,TreeNode *insert_node) {
        if(insert_node->val<node->val) {
            if(node->left)
                BST_insert(node->left,insert_node);
            else
                node->left=insert_node;
        } else {
            if(node->right)
                BST_insert(node->right,insert_node);
            else
                node->right=insert_node;
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        preorder(root,str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="")return NULL;
        int i=0;
        int t=str2int(data,i);
        TreeNode *root=new TreeNode(t);

        while(i<data.size()) {
            t=str2int(data,i);
            TreeNode* insert_node=new TreeNode(t);
            BST_insert(root,insert_node);
        }
        return root;
    }
};
```
