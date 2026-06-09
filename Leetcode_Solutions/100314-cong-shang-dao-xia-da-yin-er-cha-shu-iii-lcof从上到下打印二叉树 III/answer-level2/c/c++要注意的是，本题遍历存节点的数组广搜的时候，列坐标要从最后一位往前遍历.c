### 解题思路
本来写的，如果这轮正方向，那列坐标也正方向开始遍历，要是反方向，那列坐标也反方向。
万万没想到……这样就负负得正了！不是之字形！哭唧唧，我太笨了……

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
    vector<vector<int>> ans;
    vector<vector<TreeNode*>> arr;

    vector<int> row;//存进ans的一行
    vector<TreeNode*> r;//存进arr的一行

    int x,y;
    bool z;

    void help()
    {
        if(x>=ans.size()||y>=ans[x].size()||y<0)
        {
            //ans.push_back(row);
            return;
        }
        
        if(z==false)
        {
            if(arr[x][y]->left!=NULL)
            {
                r.push_back(arr[x][y]->left);
                row.push_back(arr[x][y]->left->val);
            }
            if(arr[x][y]->right!=NULL)
            {
                r.push_back(arr[x][y]->right);
                row.push_back(arr[x][y]->right->val);
            }
        }
        if(z==true)
        {
            if(arr[x][y]->right!=NULL)
            {
                r.push_back(arr[x][y]->right);
                row.push_back(arr[x][y]->right->val);
            }
            if(arr[x][y]->left!=NULL)
            {
                r.push_back(arr[x][y]->left);
                row.push_back(arr[x][y]->left->val);
            }
        }
        if(y==0&&!row.empty())
        {
            ans.push_back(row);
            arr.push_back(r);
            row.clear();
            r.clear();
            z=!z;
            x++;
            y=ans[x].size()-1;
        }
        else y--;
        help();

    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        x=y=0;
        z=true;
        if(root==NULL)return ans;

        r.push_back(root);
        row.push_back(root->val);

        ans.push_back(row);
        arr.push_back(r);
        
        row.clear();
        r.clear();

        help();
        return ans;
    }
};
```