### 解题思路
一开始想的是根节点和左右指针比较，后来才知道犯了个经典的错误

中序递归把二叉树节点放到一个数组里，然后对数组进行比较，即数组要单调递增。


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
bool isValidBST(TreeNode* root)
{
     if(root == NULL) return true;//数组为空
    vector<int> hei;
    isT(root,hei);
    for(int i=0;i<hei.size()-1;i++)//大于两个
    {
        if(hei[i]<hei[i+1])
        {

        }
        else return false;
    }

    return true;

}
    void isT(TreeNode* root,vector<int> & hei) {
        if(root == NULL) return ;
        //cout<<root->val<<endl;
        isT(root->left,hei);
        hei.push_back(root->val);
        isT(root->right,hei);
    }
};
```