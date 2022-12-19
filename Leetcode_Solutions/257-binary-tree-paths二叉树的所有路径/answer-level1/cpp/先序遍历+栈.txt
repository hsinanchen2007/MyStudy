### 解题思路
将已遍历的根结点组成的链表入栈，遇到叶子结点将链表压入vector
![360截图20191224112914537.jpg](https://pic.leetcode-cn.com/b490d56a6e8a0ea71eb2e5251fcfe6d3322e3c3bf1ab0a4d0e6a52dc1109c56d-360%E6%88%AA%E5%9B%BE20191224112914537.jpg)

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        if(root==NULL)
            return(res);
        stack<pair<TreeNode*,string>>sp;
        string s;
        sp.push(make_pair(root,s));
        while(!sp.empty())
        {
            TreeNode*node=sp.top().first;
            s=sp.top().second;
            sp.pop();
            string a=to_string(node->val);
            s.insert(s.size(),a);
            if((!node->left)&&(!node->right))
                res.push_back(s);
            else
            {
                s=s+'-'+'>';
                if(node->left)
                    sp.push(make_pair(node->left,s));
                if(node->right)
                    sp.push(make_pair(node->right,s));
            }
        }
        return(res);
    }
};
```