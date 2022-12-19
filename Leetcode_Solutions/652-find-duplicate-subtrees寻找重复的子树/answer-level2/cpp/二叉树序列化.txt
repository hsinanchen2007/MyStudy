### 解题思路
    //思路：问题的难点在于如何在遍历的时候对之前遍历过的子树进行描述和保存。
    //这里就需要使用之前使用过的二叉树序列化的手法，将遍历到的二叉树进行序列化表达，
    //我们知道序列化的二叉树可以唯一的表示一棵二叉树，并可以用来反序列化。
    // 我们只需在遍历的过程中将每次的序列化结果保存到一个HashMap中，并对其进行计数，如果重复出现了
    //那么将当前的节点添加到res中即可

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
   //思路：问题的难点在于如何在遍历的时候对之前遍历过的子树进行描述和保存。
    //这里就需要使用之前使用过的二叉树序列化的手法，将遍历到的二叉树进行序列化表达，
    //我们知道序列化的二叉树可以唯一的表示一棵二叉树，并可以用来反序列化。
    // 我们只需在遍历的过程中将每次的序列化结果保存到一个HashMap中，并对其进行计数，如果重复出现了
    //那么将当前的节点添加到res中即可
    vector<TreeNode *> res;
    unordered_map<string,int> temp;
    int i = 0;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }
    string dfs(TreeNode *node){
        if(node == NULL) {return "#";}
        string cur = "";
        cur += to_string(node->val) + "," + dfs(node->left) + "," + dfs(node->right);
        temp[cur]++;
        if(temp[cur] == 2){res.push_back(node);}
        return cur;
    }
};
```