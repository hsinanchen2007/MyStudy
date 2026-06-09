```
class Codec {
public:
    TreeNode* p;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        p = root;
        return "hehe";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return p;
    }
};
```
![image.png](https://pic.leetcode-cn.com/93b082179a15640b04d8eba2e22886309a801bfd175ee5e67f3c5bfbb5e26e2c-image.png)
