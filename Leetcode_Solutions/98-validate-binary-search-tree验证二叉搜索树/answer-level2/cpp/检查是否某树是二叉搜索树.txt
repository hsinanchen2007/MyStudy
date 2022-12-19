### 解题思路
此题简直坑爹，VS和leetcode上在对small=LONG_MIN时输出结果不一致= =
中序遍历非常适用于二叉搜索树，可以保证每个节点比下个节点小，所以利用这个性质进行判断。
此外由于本题有大量的INT_MIN测试用例，所以还得保证起始节点不会因为其为int最小值而算法错误，所以加了一个init来跳过
第一个节点的判断= =

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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr )
            return true;
        stack<pair<TreeNode*,bool>> stackBST;
        stackBST.push(make_pair(root,false));
        bool visited;
        int small = INT_MIN;
        bool initial =false;
        while(!stackBST.empty()){
            root = stackBST.top().first;
            visited = stackBST.top().second;
            stackBST.pop();
            if(root == nullptr)
                continue;
            if(visited){
                if(root->val <=small && initial)
                    return false;
                initial = true;
                small = root->val;
            }
            else{
                stackBST.push(make_pair(root->right,false));
                stackBST.push(make_pair(root,true));
                stackBST.push(make_pair(root->left,false));
            }
        }
        return true;
    }
};
```