### 解题思路
递归遍历&回溯算法

### 代码

```java []
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        res = new ArrayList<>();
        if(root == null)
            return res;

        ArrayList<Integer> path = new ArrayList<>();
        int pathValue = 0;
        preOrder(root, path, sum, pathValue);

        return res;
    }

    private void preOrder(TreeNode node, ArrayList<Integer> path, int sum, int pValue) {
        if(node == null)
            return;

        pValue += node.val;
        path.add(node.val);
        if(pValue == sum && node.left==null && node.right==null)
            res.add(new ArrayList<Integer>(path));

        preOrder(node.left, path, sum, pValue);
        preOrder(node.right, path, sum, pValue);

        pValue -= node.val;
        path.remove(path.size()-1);
    }

    private List<List<Integer>> res;
}
```
```python []
class Solution:
    def __init__(self):
        self.res = []

    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        # 列表作为参数的传引用性质, 需要改变递归调用的方式
        if root == None:
            return self.res
        
        path = []
        self.getPath(root, path, sum)
        return self.res

    def getPath(self, node, path, Sum):
        if node.left == None and node.right == None:
            if node.val == Sum:
                path.append(node.val)
                self.res.append(list(path))
            return
        
        if node.left != None:
            self.getPath(node.left, path+[node.val], Sum-node.val)
        if node.right != None:
            self.getPath(node.right, path+[node.val], Sum-node.val)
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return res;

        vector<int> p;
        getPath(root, sum, p);

        return res;
    }

private:
    void getPath(TreeNode *node, int sum, vector<int> p){
        if(node->left == nullptr && node->right==nullptr){
            if(sum == node->val){
                p.push_back(node->val);
                res.push_back(p);
            }
            return;
        }
            
        p.push_back(node->val);
        if(node->left != nullptr)
            getPath(node->left, sum-node->val, p);

        if(node->right != nullptr)
            getPath(node->right, sum-node->val, p);

        
    }

private:
    vector<vector<int>> res;
};
```