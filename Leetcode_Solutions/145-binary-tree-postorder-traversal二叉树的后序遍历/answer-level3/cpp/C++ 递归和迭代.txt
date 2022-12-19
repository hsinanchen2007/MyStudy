### 解题思路
分为 递归 和 迭代 两种，其中递归最为简单，只需先左后右的递归 最后再保存结点即可
迭代 利用后序为前序结果逆序的特点进行运算

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
 
/*递归*/
class Solution {
public:
    void recursive(TreeNode* root, vector<int>& res){ //记得用&引用 才能改变vector
        if(root!=NULL){
            dfs(root->left, res);
            dfs(root->right, res);
            res.push_back(root->val);
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        recursive(root, res);
        return res;
    }
};


/*迭代 参考：https://www.cnblogs.com/qjmnong/p/9135386.html*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> output,res;
        stack<TreeNode*> temp;
        if(root==NULL)  return output;
        temp.push(root);
        while(!temp.empty()){
            // 先将结点进行前序存储
            TreeNode* node = temp.top();
            temp.pop(); 
            output.push_back(node->val);
            //先存左子结点 再存右子结点 满足前序遍历
            if(node->left)  temp.push(node->left);
            if(node->right) temp.push(node->right);
        }
        // 再反向输出 完成后序遍历
        for(int i=output.size()-1;i>=0;i--)
            res.push_back(output[i]); 

        return res; 
    }
};
```
递归：
![TIM图片20191213113540.png](https://pic.leetcode-cn.com/0aebbd64761d1d35e9f9555ec9fc514f33bea3d10e8ac3c0cd68ab8b495da4eb-TIM%E5%9B%BE%E7%89%8720191213113540.png)

迭代：
![1.png](https://pic.leetcode-cn.com/19dc22197cbb12a90f18b963aebdce50e6022a93cbd23b2a0790e0a10801922a-1.png)

