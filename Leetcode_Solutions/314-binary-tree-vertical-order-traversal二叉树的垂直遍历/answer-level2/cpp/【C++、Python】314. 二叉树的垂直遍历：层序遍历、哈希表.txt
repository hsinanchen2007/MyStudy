#### 思路 ####
- 若把节点的列号设为 $col$，则左子节点的列号为 $col - 1$，右子节点的列号为 $col + 1$
- 建立哈希映射，将列号相同的元素依次加入同一个数组
- 为了保证数组中的顺序是从上到下的，直接采用层序遍历
#### 代码 ####
```cpp []
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        int lo = INT_MAX, hi = INT_MIN;
        unordered_map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q; q.push(make_pair(root, 0));
        // 上一行如果写成“queue<pair<TreeNode*, int>> q({{root, 0}});”，整个代码块都不能正常高亮显示
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto &&[node, col] = q.front();
                lo = min(lo, col);
                hi = max(hi, col);
                m[col].emplace_back(node->val);
                if (node->left) q.push({node->left, col - 1});
                if (node->right) q.push({node->right, col + 1});
                q.pop();
            }
        }
        vector<vector<int>> res;
        for (int i = lo; i <= hi; ++i) res.emplace_back(m[i]);
        return res;
    }
};
```
```python []
class Solution:
    def verticalOrder(self, root: TreeNode) -> List[List[int]]:
        if not root: return []
        queue = collections.deque(((root, 0),))
        hashMap = collections.defaultdict(list)
        lo, hi = float("inf"), float("-inf")
        while queue:
            size = len(queue)
            for i in range(size):
                node, col = queue.popleft()
                lo = min(lo, col)
                hi = max(hi, col)
                hashMap[col].append(node.val)
                if node.left: queue.append((node.left, col - 1))
                if node.right: queue.append((node.right, col + 1))
        return tuple(hashMap[i] for i in range(lo, hi + 1))
```


