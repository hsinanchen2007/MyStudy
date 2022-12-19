### 解题思路
1. 用变量`ans`存储当前最小的字符串
2. 深度优先搜索得到从根到叶节点的字符串，翻转得到从叶节点到根的字符串，与当前最小字符串比较
3. 若小于当前字符串就更新`ans`。直到遍历完所有的字符串，即可得到结果

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
    string ans = "z";
    void reverse(string& s){
        int len = s.size()-1;
        int mid = len/2;
        int i = 0;
        while(i<=mid){
            char temp = s[i];
            s[i] = s[len-i];
            s[len-i] = temp;
            i++;
        }
    }

    void dfs(TreeNode* root, string s){
        s += char('a' + root->val);
        if(root->left == NULL && root->right == NULL){
            reverse(s);
            if(s < ans) ans = s;
        }
        if(root->left) dfs(root->left, s);
        if(root->right) dfs(root->right, s);
    }

    string smallestFromLeaf(TreeNode* root) {
        if(root==NULL) return ans;
        dfs(root, "");
        return ans;
    }
};
```