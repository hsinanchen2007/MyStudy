### 解题思路
根据后序遍历确定根的位置,递归构造右子树和左子树。
由于没有重复元素，所以可以用哈希表来存储根节点的
索引。

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
    unordered_map<int,int>in;//存根节点的索引
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++)in[inorder[i]]=i;
        return dfs(postorder,inorder,0,n-1,0,n-1);
    }
    TreeNode* dfs(vector<int>& postorder, vector<int>& inorder,int pl,int pr,int il,int ir){
        if(pl>pr)return NULL;
        int val = postorder[pr]; //根节点的val
        int k = in[val],len = ir-k; //len是右子树的长度
        auto root = new TreeNode(val);
        root->right=dfs(postorder,inorder,pr-len,pr-1,k+1,ir); //当前的pr为根节点，递归建立右子树 仔细思考一下后序和中序的递归索引
        root->left=dfs(postorder,inorder,pl,pr-len-1,il,k-1); //递归建立左子树，同 仔细思考一下后序和中序的索引
        return root;
    }
};
```