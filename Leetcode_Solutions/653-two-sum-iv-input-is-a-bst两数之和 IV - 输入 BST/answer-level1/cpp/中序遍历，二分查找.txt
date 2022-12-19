### 解题思路
中序遍历二叉树，得到的便是由小到大的数，放在num中
在二分查找判断是否存在两个数满足条件

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
    bool findTarget(TreeNode* root, int k) {
        inOrder(root);
        int i=0,j=num.size()-1;
        while(i<j)
        {
            if(num[i]+num[j]>k)
            j--;
            else if(num[i]+num[j]<k)
            i++;
            else
            return true;
        }
        return false;
    }
private:
    vector<int> num;
private:
    void inOrder(TreeNode* root)
    {
        if(root==NULL) return;
        inOrder(root->left);
        num.push_back(root->val);
        inOrder(root->right);
    }
};
```