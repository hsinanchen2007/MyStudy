### 解题思路
中序遍历为不下降序列

### 代码

```java []
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isValidBST(TreeNode root) {
        if(root == null)
            return true;
        if(root.left == null && root.right == null)
            return true;
        
        // BST中序遍历为不下降序列
        inRes = new ArrayList<>();
        inOrder(root);
        for(int i=1; i<inRes.size(); ++i){
            if(inRes.get(i) <= inRes.get(i-1))
                return false;
        }
        return true;
    }

    private void inOrder(TreeNode node){
        if(node == null)
            return;

        inOrder(node.left);
        inRes.add(node.val);
        inOrder(node.right);
    }

    private List<Integer> inRes;
}
```
```python []
class Solution:
    lastVal = float('-inf')
    def isValidBST(self, root: TreeNode) -> bool:
        if root == None:
            return True

        if self.isValidBST(root.left):
            if self.lastVal < root.val:
                self.lastVal = root.val
                return self.isValidBST(root.right)
                
        return False
```
```c++ []
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;
        if(root->left == nullptr && root->right == nullptr)
            return true;
        
        inOrder(root);
        // 使用中序遍历验证BST, 得到不下降的序列
        for(int i=1; i<inRes.size(); ++i){
            if(inRes[i] <= inRes[i-1])
                return false;
        }

        return true;
    }

private:
    void inOrder(TreeNode *node){
        if(node == nullptr)
            return;

        inOrder(node->left);
        inRes.push_back(node->val);
        inOrder(node->right);
    }

private:
    vector<int> inRes;
};
```
