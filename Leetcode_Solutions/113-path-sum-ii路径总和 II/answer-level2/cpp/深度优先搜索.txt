### 解题思路
深度优先遍历树，当遍历到叶子节点时判断此条路径和是否符合要求。
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
    void paths(TreeNode* root, int nowsum, int endsum, vector<int> path, vector<vector<int> >& ans)  //参数分别为节点、当前路径和、要求路径和、路径数组、答案数组
      //注意参数path不能为数组地址vector<int>& path，若为地址的话，存储的不是一条路径，而是当前遍历过得所有节点
    {
        if(root != NULL)
        {
            nowsum += root -> val;  //更新当前和
            path.push_back(root -> val);  //节点值加入当前路径
            if(root -> left == NULL && root -> right == NULL)  //注意先判断是否为叶子结点，不能先判断nowsum==endsum，如果先判断nowsum==endsum，会出现错误减掉路径的情况
            {
                if(nowsum == endsum)
                    ans.push_back(path);
            }
            else
            {
            paths(root -> left, nowsum, endsum, path, ans);
            paths(root -> right, nowsum, endsum, path, ans);
            }
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ans;
        vector<int> path;
        paths(root, 0, sum, path, ans);  
        return ans;   
    }
};
```