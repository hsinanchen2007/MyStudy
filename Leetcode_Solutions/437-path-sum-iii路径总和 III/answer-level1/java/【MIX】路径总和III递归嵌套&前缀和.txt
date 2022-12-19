### 解题思路
总递归: 在root为根节点的二叉树中寻找和为sum的路径
子递归: 在包含node的节点中寻找和为sum的路径

### 代码

**递归嵌套**
```java []
class Solution {
    // 总递归
    public int pathSum(TreeNode root, int sum) {
        if(root == null)
            return 0;
        int res = findPath(root, sum);
        // left tree
        res += pathSum(root.left, sum);

        // right tree
        res += pathSum(root.right, sum);

        return res;
    }

    // 子递归
    private int findPath(TreeNode node, int sum){
        if(node != null){
            int res = 0;
            if(node.val == sum)
                res += 1;
            res += findPath(node.left, sum-node.val);
            res += findPath(node.right, sum-node.val);
            return res;
        }
        return 0;
    }
}
```
```python []
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        # 双重递归
        if root == None:
            return 0

        res = self.findPath(root, sum)
        res += self.pathSum(root.left, sum) + self.pathSum(root.right, sum)
        return res

    def findPath(self, node: TreeNode, sum: int) -> int:
        if node != None:
            res = 0
            if node.val == sum:
                res += 1
            res += self.findPath(node.left, sum-node.val) + self.findPath(node.right, sum-node.val)
            return res
        return 0
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
    // 总递归
    // 在以root为根节点的二叉树中,寻找和为sum的路径, 返回路径的个数
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return 0;
        
        int res = findPath(root, sum);
        // 在左子树中寻找和为sum的路径
        res += pathSum(root->left, sum);
        // 在右子树中寻找和为sum的路径
        res += pathSum(root->right, sum);
        return res;
    }

private:
    // 子递归
    // 以node为根节点的二叉树中,寻找包含node的路径,和为sum, 返回路径的个数
    int findPath(TreeNode *node, int sum){
        if(node != nullptr){
            int res = 0;
            if(node->val == sum)
                res+=1;

            res += findPath(node->left, sum-node->val);
            res += findPath(node->right, sum-node->val);
            return res;
        }
        return 0;
    }
};
```
**前缀和**
```c++ []
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        // 前缀和解法, 时间复杂度为O(N)
        // 设置前缀和为0的path为1, 当前前缀和为0
        this->rec[0] = 1;
        return findPath(root, sum, 0);
    }

private:
    int findPath(TreeNode *node, int sum, int preSum){
        if(node != nullptr){
            int res = 0;
            preSum += node->val;
            res += rec[preSum-sum];
            rec[preSum]++;
            // 递归左右子树
            res += findPath(node->left, sum, preSum) + findPath(node->right, sum, preSum);
            // 在回溯中去除不属于前缀的记录
            rec[preSum]--;
            return res;
        }
        return 0;
    }

private:
    unordered_map<int, int> rec;
};
```