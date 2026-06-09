### 解题思路
使用Map存储元素和出现的次数。
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
    map<int, int> ints;
    int TreeSum(TreeNode* root)
    {
        int leftsum = 0, rightsum = 0;
        if(root -> left == NULL && root -> right == NULL) return root -> val;  //递归边界
        if(root -> left != NULL)  //左子树不为空
        {
        leftsum = TreeSum(root -> left);
        ints[leftsum] ++;
        }
        if(root -> right != NULL)  //右子树不为空
        {
        rightsum = TreeSum(root -> right);
        ints[rightsum] ++;
        }
        return  root -> val + leftsum + rightsum;       
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        int sum = TreeSum(root);  //存储整棵树的和
        ints[sum] ++;
        int flag = 0;
        for(map<int, int>::iterator it = ints.begin(); it != ints.end(); it ++)  //遍历Map，得到出现次数最大的值（不会Map的值排序。。。）
        flag = max(flag, it -> second);
        for(map<int, int>::iterator it = ints.begin(); it != ints.end(); it ++)  
        if(it -> second == flag)
        ans.push_back(it -> first);
        return ans;
    }
};
```