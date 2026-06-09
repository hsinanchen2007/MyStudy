### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/f23e2367b4670dc08a05c824eaa245f5e77b3a146f9c8b649eb8e2e21df2fe01-image.png)


### 代码

```cpp
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> res={};
        string route = "";
        if(!root){
            return res;
        }
        RecordRoute(res, route, root);
        return res;
    }
    //traceback
    void RecordRoute(vector<string> &res, string route, TreeNode* node)
    {
        if(!node->right && !node->left){
            route+=valToString(node->val);
            res.emplace_back(route);
            return;
        }
        string nodeValString =valToString(node->val);
        route+=nodeValString+"->";
        if(node->left){
            RecordRoute(res, route, node->left);
        }
        if(node->right){
            RecordRoute(res, route, node->right);
        }
    }
    string valToString(int val){
        string x ="";
        string sign = val<0? "-":"";
        val = abs(val);
        while(val){
            int i = val%10;
            val/=10;
            x+=(i+'0');
        }
        reverse(x.begin(), x.end());
        return sign+x;
    }
};
```