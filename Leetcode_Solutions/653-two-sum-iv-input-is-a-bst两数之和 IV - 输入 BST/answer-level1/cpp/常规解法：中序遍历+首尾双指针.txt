```
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
private:
    vector<int> arr;
public:
    void middleAccess(TreeNode* root)
    {
        if(root == NULL)
            return;
        middleAccess(root->left);
        arr.push_back(root->val);    
        middleAccess(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        middleAccess(root);
        // 方法1：双重循环，太慢
        // for(int i=0;i<arr.size()-1;i++)
        // {
        //     for(int j=i+1;j<arr.size();j++)
        //     {
        //         if(arr[i] + arr[j] == k)
        //             return true;
        //     }
        // }
        
        // 方法2：首尾双指针
        int i = 0, j = arr.size()-1;
        
        while(j > i && arr[i] + arr[j] != k)
        {
            if(arr[i] + arr[j] > k)
                j--;
            else
                i++;
        }
  
        if(i == j)
            return false;
        else
            return arr[i] + arr[j] == k;
    }
};
```