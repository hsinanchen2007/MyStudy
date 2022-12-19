### 解题思路
结合二叉树的深度优先搜索遍历，遍历时注意保存根结点到叶结点的二进制字符串
遍历后二叉树后，再将二进制字符串转为十进制进行和的计算

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
    int sumRootToLeaf(TreeNode* root) {
        long sum = 0;
        vector<string> res;
        string s("");
        preOrder(root, res, s);
        for(auto str : res)
        {
            sum += B2D(str);
        }
        return sum % ((long)pow(10, 9) + 7);
    }

    //先序遍历
    void preOrder(TreeNode* root, vector<string> &res, string s)
    {
        if(root == NULL)
            return;
        //叶结点
        if(root->left == NULL && root->right == NULL)
        {
            s.append(to_string(root->val));
            //把从根结点到叶结点的二进制字符串保存到res
            res.push_back(s);
            return;
        }
        
        //分支结点
         s.append(to_string(root->val));
         //遍历左子树
         preOrder(root->left, res, s);
         //遍历右子树
         preOrder(root->right, res, s);
         //回溯
         s.pop_back();
    }

    //二进制转十进制
    long B2D (string s){
        long ans = 0;
        int p = 1;  //权重
        for(int i = s.size() - 1; i >= 0; i--)
        {
            int x = s[i] - '0';
            ans += x * p;
            p *= 2;  // p = p * 2; 
        }
        return ans;
    }
};
```