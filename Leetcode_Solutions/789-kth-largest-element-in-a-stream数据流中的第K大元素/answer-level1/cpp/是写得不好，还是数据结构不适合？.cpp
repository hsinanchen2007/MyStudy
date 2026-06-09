    这题是在二叉搜索树那张卡片里面做到的，所以用了二叉搜索树，没想到。。。
![批注 2019-12-15 200457.png](https://pic.leetcode-cn.com/9e5690ea3fed4a9512c76f8c0c56baa5a048f206f036a41f09a6bfee33dd40e5-%E6%89%B9%E6%B3%A8%202019-12-15%20200457.png)
    （感觉自己好菜）
    以下是代码：
```
struct tree_node {
    int val;
    int count;
    tree_node* left;
    tree_node* right;
    tree_node(int x) : val(x), left(NULL), right(NULL), count(1) {}
};

class KthLargest {
    int K;
    tree_node* root;
    tree_node* add_node(tree_node* root, int val) {
        if (!root) return new tree_node(val);
        if (val <= root->val) {
            root->count += 1;
            root->left = add_node(root->left, val);
        } else {
            root->count += 1;
            root->right = add_node(root->right, val);
        }        
        return root; 
    }
    int find_num(tree_node* tree_root ,int k) {
        int m = 1;
        if (tree_root->right != NULL) m = tree_root->right->count + 1;
        if (k == m) return tree_root->val;
        if (k < m) {
            return find_num(tree_root->right, k);
        } else {
            return find_num(tree_root->left, k-m);
        }
    }
public:
    KthLargest(int k, vector<int>& nums) : K(k), root(NULL) {
        for (auto i : nums) {
            root = add_node(root, i);
        }
    }
    
    int add(int val) {
        root = add_node(root, val);
        return find_num(root, K);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```

