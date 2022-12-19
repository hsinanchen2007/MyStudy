### 解题思路
效率一般，执行时间击败45.05%
为了表达简单：
1、DFS的时候把儿子的值作为字符加入父亲的字符串中；
2、最后对叶子结点的字符串值转换成整数，加入结果即可

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
    int re=0;
    int sumNumbers(TreeNode* root) {
        //算出所有的叶子节点代表的值，加入re；
        if (root==NULL) return 0;
        string s;
        DFS(root, s);
        return re;
    }
    void DFS(TreeNode* root, string s){
        s+=root->val+'0';//把儿子的值加入父亲的字符串中
        if (root->left == NULL && root->right == NULL){//是叶子结点
            re+=Tran(s);
            return;
        }
        
        if (root->left != NULL) DFS(root->left, s);
        if (root->right != NULL)DFS(root->right, s);
        return;
    }
    int Tran(string s){//字符串转化为整数
        int n=s.size()-1;
        int r=0;
        for(int i=0; i<s.size(); i++){
            r+=(s[i]-'0')*pow(10, n);
            n--;
        }
        return r;
    }
};
```