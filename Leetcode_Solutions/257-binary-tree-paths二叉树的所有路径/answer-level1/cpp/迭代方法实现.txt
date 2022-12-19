### 解题思路
![image.png](https://pic.leetcode-cn.com/a93e4134817d819053dfff8aa3353a2744062c37641c3026ae834a483d1ff83c-image.png)

思路比较简单，root空的时候返回空，root没有子节点的时候返回to_string(root->val)，其余时候利用迭代的思想，构建新的vector并返回

### 代码

```cpp
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        if (root==NULL) return {};
        if (!root->left && !root->right) return {to_string(root->val)};

        vector<string> result={};
        vector<string> left = binaryTreePaths(root->left);
        vector<string> right = binaryTreePaths(root->right);
        for (int i = 0; i < left.size(); i++)
            result.push_back(to_string(root->val) + "->" + left[i]);
        for (int j = 0; j < right.size(); j++)
            result.push_back(to_string(root->val) + "->" + right[j]);
            
        return result;
    }
};
```