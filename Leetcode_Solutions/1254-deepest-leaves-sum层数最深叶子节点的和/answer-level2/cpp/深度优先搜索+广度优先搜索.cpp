**方法一：深度优先搜索**
1.使用全局变量maxLevel来记录当前树的最大深度
2.dfs递归遍历二叉树，若当前层数等于记录的最大深度，则累加结果ans
3.若当前层数大于记录的最大深度，则更新最大深度maxLevel和结果ans
```
class Solution {
private:
    int maxLevel = 0, ans = 0;
    void dfs(TreeNode* node, int level) {
        if(node == nullptr) return;
        if(level == maxLevel) ans += node->val;
        if(level > maxLevel) ans = node->val, maxLevel = level;
        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};
```
**时间复杂度：O(N),遍历二叉树**
**空间复杂度：O(N),最坏情况为O(N),最好情况为O(log(N))**

**方法二：广度优先搜索**
基于之前练习的题目：[102.二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

![image.png](https://pic.leetcode-cn.com/3d561034c8bfa63ef9c3e13367f8984dfa469a9dfb5ab179780ac703f2f34ad9-image.png)
1.使用广度优先搜索对二叉树进行层次遍历，遍历结果存储于二维向量中
2.此时二维向量的最后一组值即为层数最深的叶子节点
3.遍历向量求和
```
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(root == nullptr) return 0;
        vector<vector<int>> tree;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int levelSize = q.size();
            vector<int> cur;
            for(int i = 0; i < levelSize; i++) {
                TreeNode* curNode = q.front();
                q.pop();
                cur.push_back(curNode->val);
                if(curNode->left != nullptr)
                    q.push(curNode->left);
                if(curNode->right != nullptr)
                    q.push(curNode->right);
            }
            tree.push_back(cur);
        } 
        int ans = 0;
        int n = tree.size()-1;
        int m = tree[n].size();
        for(int i = 0; i < m; i++) {
            ans = ans + tree[n][i];
        }
        return ans;
    }
};
```
**时间复杂度：O(N),遍历二叉树**
**空间复杂度：O(N),使用了额外的队列与总大小为N的向量**

ps:刚刚练习树的题目，不太熟练，大佬们对于上述代码有什么优化的方法、或者小伙伴们有什么疑问的，欢迎在评论区讨论指正哈！