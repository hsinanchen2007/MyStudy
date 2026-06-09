### 解题思路


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
    unordered_map<int,int> map;
    TreeNode* buildTree(vector<int>& vpre, vector<int>& vin) {
        if(!vpre.size() || !vin.size() || vpre.size() != vin.size()) return NULL;
        //记录中序遍历序列中各元素值所对应的下标
        for(int i = 0;i < vin.size();i++) map[vin[i]] = i;

        return dfs(vpre,vin,0,vpre.size() -1 ,0,vin.size() - 1);
    }
    TreeNode* dfs(vector<int> &vpre,vector<int>& vin,int pl,int pr,int il,int ir){
        if(pl > pr) return NULL;//递归终止条件
        
        //初始化根节点
        int rval = vpre[pl];
        auto root = new TreeNode(rval);

        int k = map[rval];  //找到根节点在中序遍历序列中的下标

        //递归创建根节点的左右子树
        root->left = dfs(vpre,vin,pl+1,pl+k-il,il,k-1);
        root->right = dfs(vpre,vin,pl+k-il+1,pr,k+1,ir);

        return root;
    }
};
```