### 解题思路
BFS遍历, 使用Pair存入Level信息, java实现可以创建内部类

### 代码

```java []
class Solution {
    private class Pair{
        Pair(TreeNode node, int level){
            this.node = node;
            this.level = level;
        }

        TreeNode node;
        int level;
    }

    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if(root == null)
            return res;
        // BFS
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(root, 0));
        while(!q.isEmpty()){
            Pair p = q.remove();
            TreeNode node = p.node;
            int level = p.level;
            if(level == res.size())
                res.add(new ArrayList<Integer>());
            res.get(level).add(node.val);
            if(node.left != null)
                q.add(new Pair(node.left, level+1));
            if(node.right != null)
                q.add(new Pair(node.right, level+1));
        }
        return res;
    }
}
```
```python []
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root == None:
            return []

        res = []
        self.__levelOrder(root, 0, res)
        return res

    def __levelOrder(self, node:TreeNode, level:int, res:[]):
        if node == None:
            return

        if level == len(res):
            res.append([])
        res[level].append(node.val)

        if node.left != None:
            self.__levelOrder(node.left, level+1, res)
        if node.right != None:
            self.__levelOrder(node.right, level+1, res) 

```
```c++ []
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 二叉树的层次遍历, 使用BFS算法
        vector<vector<int>> res;
        if(root == nullptr)
            return res;
        // 队列中存储层次信息
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        vector<int> vec;
        vec.clear();
        while(!q.empty()){
            TreeNode *node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            // 创建存储vector
            if(level == res.size())
                res.push_back(vector<int>());
            // 压入层节点
            res[level].push_back(node->val);
            
            if(node->left != nullptr)
                q.push(make_pair(node->left, level+1));
            if(node->right != nullptr)
                q.push(make_pair(node->right, level+1));
        }
        return res;
    }
};
```