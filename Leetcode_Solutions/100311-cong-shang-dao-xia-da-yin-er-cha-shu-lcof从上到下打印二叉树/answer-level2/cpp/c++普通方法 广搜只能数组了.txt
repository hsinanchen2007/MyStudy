### 解题思路
广搜那就只能存数组了，将头节点及其val存进arr[0]和ans。
设一个路标local，代表我们已经遍历过的节点所在arr中的位置。
然后以arr[0]为入口，顺着arr[local]的位置依此往后遍历，每遍历一个节点就把它的左右孩子push到arr的尾部。
同时往ans中存当前节点的val。

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
    vector<TreeNode*> arr;//存所有节点
    vector<int> ans;//存val
    int local;
    void help()
    {
        //cout<<arr[local]->val<<endl;
        if(local>=arr.size())return;
        if(arr[local]->left!=NULL)
        {
            arr.push_back(arr[local]->left);
            ans.push_back(arr[local]->left->val);
        }
        if(arr[local]->right!=NULL)
        {
            arr.push_back(arr[local]->right);
            ans.push_back(arr[local]->right->val);
        }
        local++;
        help();
    }
    vector<int> levelOrder(TreeNode* root) {
        if(root==NULL)return ans;
        arr.push_back(root);
        ans.push_back(root->val);
        local=0;
        help();
        return ans;
    }
};
```