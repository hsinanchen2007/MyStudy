### 解题思路
此处撰写解题思路

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
    int _ret;
public:
    int maxSumBST(TreeNode* root) {
        // from yezi , wang shang digui ,ruguo nali gua le ,name jiu shangmian dou guale 
        _ret = 0;
        int temp = 0;
        _max(root, temp);
        return max(_ret, 0);
    }
    bool _max(TreeNode* root, int& sum)
    {
        if(!root)return false;
        bool bsuc = true;
        if(root->left)
        {
            int suml = 0;
            do{
                if(!_max(root->left, suml) ){
                    bsuc = false;
                    break;
                }
                if(root->left->val >= root->val)
                {
                    bsuc = false;
                    break;
                }
                sum += suml;
            }while(0);
        }
        if(root->right)
        {
            int sumr = 0;
            do{
                if(!_max(root->right, sumr))
                {
                    bsuc = false;
                    break;
                }
                if(root->val >= root->right->val)
                {
                    bsuc = false;
                    break;
                }
                sum += sumr;
            }while(0);
        }
        sum += root->val;
        if(bsuc == false )return false;
        if(_ret < sum)
        {
            _ret = sum;
           // cout<<root->val<<" "<<sum<<endl;
        }

        return true;
    }
};
```