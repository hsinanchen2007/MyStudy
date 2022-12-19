
```c++ []
class Codec {
public:
    TreeNode* encode(Node* root) {
        if (!root) return NULL;
        TreeNode *res = new TreeNode(root->val);
        if (!root->children.empty()) {
            res->left = encode(root->children[0]);
        }
        TreeNode *cur = res->left;
        for (int i = 1; i < root->children.size(); ++i) {
            cur->right = encode(root->children[i]);
            cur = cur->right;
        }
        return res;
    }

    Node* decode(TreeNode* root) {
        if (!root) return NULL;
        Node *res = new Node(root->val, {});
        TreeNode *cur = root->left;
        while (cur) {
            res->children.push_back(decode(cur));
            cur = cur->right;
        }
        return res;
    }
};
```
```python []
class Codec:

    def encode(self, root):
        """Encodes an n-ary tree to a binary tree.
        
        :type root: Node
        :rtype: TreeNode
        """
        if root is None: return None
        res =  TreeNode(root.val)
        if(len(root.children) != 0): 
            res.left = self.encode(root.children[0])
        cur = res.left
        for i in range(1, len(root.children)):
            cur.right = self.encode(root.children[i])
            cur = cur.right
        return res

    def decode(self, root):
        """Decodes your binary tree to an n-ary tree.
        
        :type root: TreeNode
        :rtype: Node
        """
        if not root: return None
        res = Node(root.val, [])
        cur = root.left
        while(cur):
            res.children.append(self.decode(cur))
            cur = cur.right
        return res

```

