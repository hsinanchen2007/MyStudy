### 解题思路
257题和112题的结合。

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
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0; 
        int count(0);
        int add(0);
        queue<TreeNode*> que;
        que.push(root);
        //层序遍历每一个结点
        while(!que.empty()){
            TreeNode* node = que.front();
            //找 当前结点 有多少个路径
            count += oneNodePathSum(node,sum,add);
            que.pop();
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
        return count;
    }
private:
    //int add = 0;
    //int count = 0;
    int oneNodePathSum(TreeNode* root, int sum, int add){//add只能从这里
        if(!root) return 0;
        //count可以在这里定义，因为它可以通过return传递
        int count(0);
        //int add(0); 注意，绝对不可以在这里定义add，否则每次回溯都会把add清0！！
        //add增加当前的值
        add += root->val;
        //记录递归前状态
        int temp = add;
        //如果某一条路径等于sum了，count++，不能return，因为下面可能有负数的结点，可能还有路径
        if(add==sum) ++count;
        //找左子树，不能剪枝，因为可能有负数的结点
        if(root->left){
            count += oneNodePathSum(root->left, sum,add);
            add = temp;//回溯
        }
        ////找右子树，不能剪枝，因为可能有负数的结点
        if(root->right){
            count += oneNodePathSum(root->right, sum,add);
            add = temp;//回溯
        }
        return count;
    }
};
```