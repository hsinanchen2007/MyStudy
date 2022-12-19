### 思路：
奇偶层的打印顺序不一样是相反的，可以利用层数偶数与否调用reverse来解决，但是海量数据时这个效率很低，不推荐。

因为奇数层的打印顺序是从左到右，偶数层的打印顺序是从右到左，可以利用STL容器deque中
``push_back()``,``push_front()``,``front()``,``back()``,``pop()``,``popfront()``来实现

**前取后放，后取前放**
```c++ []
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root==NULL)
            return res;
        bool flag = true; //从左向右打印为true，从右向左打印为false
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> out;
            TreeNode* node;
            while (n>0)
            {
                if (flag) // 前取后放：从左向右打印，所以从前边取，后边放入
                {
                    node = q.front();
                    q.pop_front();
                    if (node->left)
                        q.push_back(node->left);  // 下一层顺序存放至尾
                    if (node->right)
                        q.push_back(node->right);
                }
                else  //后取前放： 从右向左，从后边取，前边放入
                {
                    node = q.back();
                    q.pop_back();
                    if (node->right)
                        q.push_front(node->right);  // 下一层逆序存放至首
                    if (node->left)
                        q.push_front(node->left);
                }
                out.push_back(node->val);
                n--;
            }
            flag = !flag;
            res.push_back(out);
        }
        return res;
    }
};
```
```python []
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        if root is None:
            return res
        q = collections.deque()
        q.append(root)
        flag = True
        while q:
            n = len(q)
            out = []
            node = None
            while n>0:
                if flag:
                    node = q.popleft()
                    if node.left:
                        q.append(node.left)
                    if node.right:
                        q.append(node.right)
                else:
                    node = q.pop()
                    if node.right:
                        q.appendleft(node.right)
                    if node.left:
                        q.appendleft(node.left)
                out.append(node.val)
                n-=1
            res.append(out[:])
            flag= not flag
        return res
```

### 欢迎Star
#### [更多剑指Offer题解（C++与Python实现）](https://github.com/bryceustc/CodingInterviews)
#### [更多LeetCode题解（C++与Python实现）](https://github.com/bryceustc/LeetCode_Note)