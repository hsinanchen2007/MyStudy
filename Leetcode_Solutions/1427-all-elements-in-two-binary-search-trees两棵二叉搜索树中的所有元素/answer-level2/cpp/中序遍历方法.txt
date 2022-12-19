### 解题思路
首先使用中序遍历将第一个二叉树数据存放在数组A1中，在获取第二个二叉树数据时进行直接插入。为了防止始终自数组下标0开始遍历，加入一个index作为下一次插入下标初始查询位置。
在加入index后，执行用时自1160ms提高至508ms。

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> re;
        int index = -1;
        get(root1,re,index);
        index = 0;
        get(root2,re,index);
        return re;
    }

    void get(TreeNode* root,vector<int> &re,int index)
    {
        if(root == NULL)
        {
            return;
        }
        get(root->left,re,index);
        if(index == -1)
        {
            re.push_back(root->val);
        }
        else
        {
            while(index < re.size() && re[index]< root->val)
           {
               ++index;
           }
            if(index == re.size()){re.push_back(root->val);}
            else{
                re.insert(re.begin()+index,root->val);
            }
        }
        get(root->right,re,index);
        
    }
};
```