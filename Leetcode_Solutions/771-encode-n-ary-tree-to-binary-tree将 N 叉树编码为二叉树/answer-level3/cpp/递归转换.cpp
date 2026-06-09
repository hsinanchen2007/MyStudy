```
class Codec {
public:
    
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if(!root)
            return nullptr;
        
        TreeNode* Broot = new TreeNode(root->val);
        
        if(root->children.size() > 0)
        {
            TreeNode* node = encode(root->children[0]);
            Broot->left = node;
            for(int i = 1; i < root->children.size(); i ++)
            {
                node->right = encode(root->children[i]);
                node = node->right;
            }
        }
        
        return Broot;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
       if(!root)
           return nullptr;
        
        Node* Rroot = new Node(root->val);
        
        if(root->left)
        {
            TreeNode*  node = root->left;
            Rroot->children.push_back(decode(node));
            while(node->right)
            {
                Rroot->children.push_back(decode(node->right));
                node = node->right;
            }
        }
        return Rroot;
    }
};
```