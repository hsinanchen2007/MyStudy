### 解题思路



### 代码

可读代码：
```python []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        res, path = [], []

        def dfs(node, sum):
            #递归出口：解决子问题
            if not node: return #如果没有节点(node = None)，直接返回，不向下执行
            else:               #有节点
                path.append(node.val) #将节点值添加到path
                sum -= node.val 
            # 如果节点为叶子节点，并且 sum == 0
            if not node.left and not node.right and not sum: 
                res.append(path[:]) 

            dfs(node.left, sum) #递归处理左边
            dfs(node.right, sum) #递归处理右边
            path.pop() #处理完一个节点后，恢复初始状态，为node.left,  node.right操作

        dfs(root, sum)
        return res
```

简洁写法：
```python []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        ans, path = [],[]
        def dfs(root, sum):
            if not root: return
            path.append(root.val)
            sum -= root.val
            if not root.left and not root.right and not sum:
                ans.append(path[:])
            dfs(root.left, sum)
            dfs(root.right, sum)
            path.pop()
        
        dfs(root, sum)
        return ans

```

```cpp []
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
    vector<vector<int> > ans;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return ans;
    }
    void dfs(TreeNode* root, int sum){
        if(!root) return;
        path.push_back(root->val);
        sum -= root->val;
        if(!root->left && !root->right && !sum) ans.push_back(path);
        dfs(root->left, sum);
        dfs(root->right, sum);
        path.pop_back(); //删除向量中的最后一个元素，有效地将容器大小减小了一个。
    }
};
```
```python []
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        self.ans, self.path = [],[]    
        self.dfs(root, sum)
        return self.ans
    def dfs(self, root, sum):
        if not root: return
        self.path.append(root.val)
        sum -= root.val
        if not root.left and not root.right and not sum:
            self.ans.append(self.path[:])
        self.dfs(root.left, sum)
        self.dfs(root.right, sum)
        self.path.pop()
```
![截屏2020-03-10下午3.27.28.png](https://pic.leetcode-cn.com/d4547289c9e852abe1fc2d5872f41ccb753055f96503e9921c7c4c907dc22796-%E6%88%AA%E5%B1%8F2020-03-10%E4%B8%8B%E5%8D%883.27.28.png)


[更多《剑指 Offer》有趣题解，关注DoneIsBetter简书](https://www.jianshu.com/p/9cbdda8a3e5e)

