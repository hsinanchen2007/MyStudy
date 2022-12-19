### 解题思路
注意while和if的区别！
可以把二维数组写在函数外，作为全局变量这样可以减少调用。

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
    vector<vector<int>> res;//把res写在外面，返回用void这样运行快
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        //vector<vector<int>> res;
        vector<int> a;
        //if(root==nullptr) return res;
        printres(root,sum,a,0);
        return res;
    }
    void printres(TreeNode* root,int sum,vector<int>& a,int num)
    {
       if(root!=nullptr)//if和while傻傻搞不清楚
        {
            a.push_back(root->val);
            num=num+root->val;
            //if(root!=nullptr&&root->left==nullptr&&root->right==nullptr&&num==sum)//叶子节点
                //res.push_back(a);//写两个地方都行
        
            printres(root->left,sum,a,num);
            printres(root->right,sum,a,num);
            if(root!=nullptr&&root->left==nullptr&&root->right==nullptr&&num==sum)//叶子节点
                res.push_back(a);
            a.pop_back();num=num-root->val;
        }
        
        //return res;

    }
};
```