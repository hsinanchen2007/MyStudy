### 解题思路
1. 唯一确定一棵树 ：
【1】中序遍历 + 前序/后序/层序遍历 （ **中序：要求树中没有重复元素** ）
【2】对于二叉搜索树BST ： （ **要求树中没有重复元素** ）
只需要知道前序/后序/层序遍历中的一种，如果将已知遍历从小到大排序即为中序遍历
【3】**前序/后序/层序**序列化 （ **要求包含空指针** ）
二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果保存为字符串，其中的空结点也要保存为一个字符
注意：带空指针的中序序列化不能重建二叉树 （该序列是一个空结点字符和结点字符交叉排列的字符串）

2. 找重复的子树
将一棵二叉树的所有结点作为根节点做前序序列化，记录该前序序列化字符串出现的次数（大于1说明存在重复）
用前序遍历二叉树的所有结点
`  unordered_map<string,int> hash; ` 
key : 每个结点的前序序列化字符串 ， value ： 出现的次数
`  if(++ hash[s] == 2) res.push_back(root); `
这里不能写 `++ hash[s] > 1` ,因为比如题目示例中的结点 4 出现了3次，会重复加入结果res
或者最后再删除res中的重复元素（先sort,然后unique)

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
    vector<TreeNode*> res;
    unordered_map<string,int> hash;

    string preorder(TreeNode* root){
        if(!root) return "NULL";
        string left = preorder(root->left);
        string right = preorder(root->right);
        string s = to_string(root->val) + "," + left + "," + right;
        if(++ hash[s] == 2) res.push_back(root);
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        preorder(root);
        return res;
    }
};
```