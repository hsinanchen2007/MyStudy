### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/0b6196d7f3aefd6192bbcaaaf2bcb549fee4162f2afa7ce48e33bf96fd8f227a-image.png)

与我上一个题解相比，代码更简洁，但是运行时间更长。
### 代码

```cpp
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> res={};
        string route = "";
        RecordRoute(res, route, root);
        return res;
    }
    //traceback
    void RecordRoute(vector<string> &res, string route, TreeNode* node)
    {
        if(!node) return;
        if(!node->right && !node->left){
            route+=to_string(node->val);
            res.emplace_back(route);
            return;
        }
        route+=to_string(node->val)+"->";
        RecordRoute(res, route, node->left);
        RecordRoute(res, route, node->right);
    }
};
```