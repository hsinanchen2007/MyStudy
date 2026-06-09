### 解题思路
因为是二叉搜索树，中序遍历的到一个有序数组，然后用双指针遍历数组得到答案。
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
    vector<int> ints;
    void inorder(TreeNode* root)  //中序遍历
    {
        if(root == NULL) return ;
        inorder(root -> left);
        ints.push_back(root -> val);
        inorder(root -> right);
    }
    bool findTarget(TreeNode* root, int k) {
        bool ans = false;
        if(root == NULL) return ans;
        inorder(root);
        int left = 0, right = ints.size() - 1;
        while(left < right)  //双指针遍历数组
        {
            if(ints[left] + ints[right] == k)
            {
                ans = true;  //存在两数之和等于k
                break;
            }
            else if(ints[left] + ints[right] < k)  //两数之和小于k
            left ++;  //左指针右移
            else
            right --;  //右指针左移
        }
        return ans;
    }
};
```