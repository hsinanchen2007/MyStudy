### 解题思路

### 代码
先序遍历树。
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
    string ans;
    stringstream ss;  //将数字转换为字符串
    string s;
    void DFS(TreeNode* nownode)
    {
        if(nownode == NULL) return ;  //递归边界
        ss.clear();  //使用之前记得将缓冲区清空，否则值不会改变
        ss << nownode -> val;
        ss >> s;
        ans += s;  //先加上节点值
        if(nownode -> left != NULL )  //如果左子树不为空，则右子树为空的话不需要空括号
        {
        ans += '(';
        DFS(nownode -> left);
        ans += ')';
        if(nownode -> right != NULL)
        {
        ans += '(';
        DFS(nownode -> right);
        ans += ')';
        }
        }
        if(nownode -> left == NULL && nownode -> right != NULL)  //如果左子树为空，右子树不为空，左子树也需要保留空括号
        {
        ans += '(';
        DFS(nownode -> left);
        ans += ')';
        ans += '(';
        DFS(nownode -> right);
        ans += ')';   
        }
    }
    string tree2str(TreeNode* t) { 
        if(t == NULL)
        return ans;
        DFS(t);  
        return ans;
    }
};
```