中序遍历的同时重建树，顺序保存结果。

```
class FindElements {
private:
  vector<int> vec;
public:
    FindElements(TreeNode* root) {
        reconstruct(root, -1, false);
    }
  
    void reconstruct(TreeNode *root, int x, bool isLeft) {
      if(!root)
        return;
      root->val = isLeft ? (2*x+1) : (2*x+2);
      reconstruct(root->left, root->val, true);
      vec.push_back(root->val);
      reconstruct(root->right, root->val, false);
    }
    
    bool find(int target) {
      return std::find(vec.begin(), vec.end(), target) != vec.end();
    }
};
```

184 ms	18.5 MB

## 更快的find

用Set的话，时间复杂度是 O(1)：

```cpp
class FindElements {
private:
    unordered_set<int> dict;
public:
    FindElements(TreeNode* root) {
        if(!root)
            return;
        fill(root, 0);
    }
    
    void fill(TreeNode *root, int x) {
        root->val = x;
        dict.insert(x);
        if(root->left)
            fill(root->left, 2 * x + 1);
        if(root->right)
            fill(root->right, 2 * x + 2);
    }
    
    bool find(int target) {
      return dict.count(target) > 0;
    }
};
```

32 ms	30.1 MB