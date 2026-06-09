把N叉树转化为二叉树需要做的思考是：二叉树只能有两种状态，而且题目不允许添加更多的状态，所以我们需要将N叉树的所有节点都归纳为两种状态：
稍微思考一下，我们可以有这么一个方案： 1. 第一个状态保存子节点， 2. 第二个状态保存兄弟节点信息。
```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
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

    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
      if(root ==NULL) return NULL;
      auto troot = new TreeNode(root->val);
      bool left = true;
      auto current = troot;
      //子节点放左边，兄弟节点放右边
      for(auto node: root-> children) {
          if(left) {
              current->left = encode(node);
              current = current->left;
              left = false;
          } else {
              current -> right = encode(node);
              current = current -> right;
          }
      }
      return troot;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if(root == NULL) return NULL; 
        auto nroot =  new Node(root->val, {});
        auto current = root->left;
        while(current) {
            nroot->children.push_back(decode(current));
            current = current->right;
        }
        return nroot;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));
```

引申： 转化三叉树，四叉树， or M叉树？ 我们都只需要用一个状态保存兄弟节点，其他状态来保存子节点就行了！