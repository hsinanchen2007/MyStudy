### 算法分析
1. 定义递归函数recursive，遍历树进行序列化。定义哈希表存储序列化结果，用于判断是否重复。
2. 如果节点为空返回"#", 否则计算str = node.val + "," + recursive(node.left) + "," + recursive(node.right)
3. 将str加入哈希表，判断str是否存在于哈希表且数目为2，如果是则将node加入结果数组，返回str
4. 递归结束返回结果数组
### 复杂度分析
+ 时间复杂度：O(n^2)，n为二叉树结点数量
+ 空间复杂度：O(n^2)，哈希表和递归调用栈占用额外空间
### 源码
```C++ []
class Solution {
public:
    string recursive(TreeNode* node, unordered_map<string, int>& hashMap, vector<TreeNode*>& results)
    {
        if (node == NULL)
            return "#";

        string str = to_string(node->val) + recursive(node->left, hashMap, results) + recursive(node->right, hashMap, results);
        hashMap[str]++;

        if (hashMap[str] == 2)
            results.push_back(node);
        
        return str;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> results;
        unordered_map<string, int> hashMap;
        recursive(root, hashMap, results);
        return results;
    }
};