### 解题思路
深度优先搜索，递归解决。
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
    bool ans = false;  //全局变量，先声明为false
    void test(TreeNode* nownode, int nowsum, int sum)  
    {
        if(nowsum + nownode -> val == sum && nownode -> left == NULL && nownode -> right == NULL) ans = true;  //如果加上叶子结点的值等于sum，则更新ans为true
        else 
        {
            if(nownode -> left != NULL) 
            test(nownode -> left, nowsum + nownode -> val, sum);  //左节点不为空，循环左节点
            if(nownode -> right != NULL)
            test(nownode -> right, nowsum + nownode -> val, sum);
        }
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
        return ans;
        test(root, 0, sum);
        return ans;
    }
};
```