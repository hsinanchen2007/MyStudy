### 解题思路
方法1：动态规划，自底向上：这个方法不是很好想。效率也不高。简单的思路就是：8,3,1为例8-1的差值等于 （8-3）+ （3-1），每一次计算差值求max，同时记录差值

方法2：dfs求每条路径上的max和min，然后求差值，取最大


方法1：动态规划
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

    int maxdiff = INT32_MIN;
    vector<int> dfs(TreeNode* node){


        vector<TreeNode*> pnodes = {node->left,node->right};
        vector<int> totalvalue;

        for(auto pnode: pnodes){

            if(NULL == pnode){
                continue;
            }
 
            vector<int> values = dfs(pnode);
            int diff =  node->val - pnode->val;
            maxdiff = max(maxdiff,abs(diff));
            totalvalue.push_back(diff);

            for(auto value:values){
                maxdiff = max(maxdiff,abs(diff+ value));
                totalvalue.push_back(diff+ value);
            }
        }

        return totalvalue;

    }


    int maxAncestorDiff(TreeNode* root) {

        maxdiff = INT32_MIN;

        dfs(root);

        return  maxdiff;
        
    }
};
```

方法2：dfs求每条路径上的max和min，然后求差值，取最大
```cpp
class Solution {
public:
    int maxdiff = 0;

    void dfs(TreeNode *root, int maxvalue, int minvalue)
    {
        if (root == NULL) {
            return;
        }

        maxvalue = max(maxvalue, root->val);
        minvalue = min(minvalue, root->val);

        maxdiff = max(maxdiff, maxvalue - minvalue);

        dfs(root->left, maxvalue, minvalue);
        dfs(root->right, maxvalue, minvalue);
        return;
    }

    int maxAncestorDiff(TreeNode *root)
    {
        maxdiff = 0;
        dfs(root, root->val, root->val);
        return maxdiff;
    }
};
```
