### 解题思路
中序遍历&建立AVL树

### 代码

```java []
class Solution {
    private List<Integer> res;

    public TreeNode balanceBST(TreeNode root) {
        res = new ArrayList<>();
        dfs(root);
        return makeAVL(0, res.size());
    }

    // sort
    private void dfs(TreeNode node){
        if(node == null)
            return;
        dfs(node.left);
        res.add(node.val);
        dfs(node.right); 
    }

    // make AVL
    private TreeNode makeAVL(int start, int end){
        if(start < end){
            int mid = start + ((end-start)>>1);
            TreeNode node = new TreeNode(res.get(mid));
            node.left = makeAVL(start, mid);
            node.right = makeAVL(mid+1, end);
            return node;
        }
        return null;
    }
}
```
```python []
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        if root == None:
            return None
        self.vals = []
        self.dfs(root)
        return self.makeAVL(0, len(self.vals))

    
    # 中序遍历
    def dfs(self, node: TreeNode):
        if node is not None:
            self.dfs(node.left)
            self.vals.append(node.val)
            self.dfs(node.right)
        
        return None

    # 建立AVL树
    def makeAVL(self, start, end):
        if start < end:
            mid = start + ((end-start)>>1)
            node = TreeNode(self.vals[mid])
            node.left = self.makeAVL(start, mid)
            node.right = self.makeAVL(mid+1, end)
            return node
        
        return None
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
    TreeNode* balanceBST(TreeNode* root) {
        // 先中序遍历, 得到BST对应的有序数组, 再重新建立AVL
        if(root == nullptr)
            return nullptr;

        midOrder(root);
        return makeAVL(0, ans.size());
    }

private:
    // 中序遍历BST, 得到元素的顺序
    void midOrder(TreeNode *node){
        if(node == nullptr)
            return;
        
        midOrder(node->left);
        this->ans.push_back(node->val);
        midOrder(node->right);
    }

    // 使用二分法重新建立AVL
    TreeNode *makeAVL(int start, int end){
        if(start < end){
            int mid = start+((end-start)>>1);
            TreeNode *node = new TreeNode(ans[mid]);
            node->left = makeAVL(start, mid);
            node->right = makeAVL(mid+1, end);
            return node;
        }
        return nullptr;
    }


private:
    vector<int> ans;

};
```