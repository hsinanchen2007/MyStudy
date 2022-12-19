### 解题思路
首先递归遍历树，记录下根节点的数据，然后对数据进行排序，从数据头开始遍历，找出第二小的数据。
时间复杂度：o（n）+o（logn/2）
空间复杂度：o（n）
![image.png](https://pic.leetcode-cn.com/9d237e46ad3e0dc7bb440f39864a86a621728b53e405b08a095c6c3971589105-image.png)


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
    vector<int> answer;
    void f(TreeNode* root)
    {
        if(!root) return;
        if(!root->right) 
        {
          answer.push_back(root->val);
          return;
        }
        f(root->left);
        f(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        f(root);
        sort(answer.begin(),answer.end());
        if(root==NULL || answer.size()<2 || answer[answer.size()-1]==answer[0]) return -1;
        int count=answer[0];
        for(int x:answer)
        {
             if(x!=count) return x;
        }
        return -1;
    }
};
```