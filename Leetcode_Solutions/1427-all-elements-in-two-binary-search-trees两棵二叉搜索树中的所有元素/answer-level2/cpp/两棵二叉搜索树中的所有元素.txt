#### 方法一：遍历 + 排序

我们可以想到的最简单的方法是，对两棵树进行任意形式的遍历（深度优先搜索、广度优先搜索、前序遍历、中序遍历、后序遍历），并将遍历到的所有元素放入一个数组中，最后对这个数组进行排序即可。

```C++ [sol1-C++]
class Solution {
public:
    void dfs(TreeNode* node, vector<int>& ans) {
        if (!node) {
            return;
        }
        ans.push_back(node->val);
        dfs(node->left, ans);
        dfs(node->right, ans);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        dfs(root1, ans);
        dfs(root2, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```

```Python [sol1-Python3]
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        ans = list()

        def dfs(node):
            if not node:
                return
            ans.append(node.val)
            dfs(node.left)
            dfs(node.right)
        
        dfs(root1)
        dfs(root2)
        ans.sort()
        return ans
```

**复杂度分析**

- 时间复杂度：$O((M + N) \log (M + N))$，其中 $M$ 和 $N$ 是两棵树中的节点个数。

- 空间复杂度：$O(H_M + H_N + \log(M + N))$，其中 $H_M$ 和 $H_N$ 是两棵树的高度，这里只计算除了存储答案的数组以外需要的额外空间。上面给出的代码使用深度优先搜索对两棵树进行遍历，需要 $O(H_M + H_N)$ 的栈空间；在对数组进行排序时，需要 $\log (M + N)$ 的栈空间。

#### 方法二：中序遍历 + 归并排序

方法一中并没有用到二叉搜索树本身的性质。如果我们对二叉搜索树进行中序遍历，就可以直接得到树中所有元素升序排序后的结果。因此我们可以对两棵树分别进行中序遍历，得到数组 `v1` 和 `v2`，它们分别存放了两棵树中的所有元素，且均已有序。在这之后，我们通过归并排序的方法对 `v1` 和 `v2` 进行排序，就可以得到最终的结果。

```C++ [sol2-C++]
class Solution {
public:
    void dfs(TreeNode* node, vector<int>& v) {
        if (!node) {
            return;
        }
        dfs(node->left, v);
        v.push_back(node->val);
        dfs(node->right, v);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        dfs(root1, v1);
        dfs(root2, v2);
        
        vector<int> ans;
        int i = 0, j = 0;
        while (i < v1.size() || j < v2.size()) {
            if (i < v1.size() && (j == v2.size() || v1[i] <= v2[j])) {
                ans.push_back(v1[i++]);
            }
            else {
                ans.push_back(v2[j++]);
            }
        }
        return ans;
    }
};
```

```Python [sol2-Python3]
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        def dfs(node, v):
            if not node:
                return
            dfs(node.left, v)
            v.append(node.val)
            dfs(node.right, v)
        
        v1, v2 = list(), list()
        dfs(root1, v1)
        dfs(root2, v2)
        ans, i, j = list(), 0, 0
        while i < len(v1) or j < len(v2):
            if i < len(v1) and (j == len(v2) or v1[i] <= v2[j]):
                ans.append(v1[i])
                i += 1
            else:
                ans.append(v2[j])
                j += 1
        return ans
```

**复杂度分析**

- 时间复杂度：$O(M + N)$，其中 $M$ 和 $N$ 是两棵树中的节点个数。中序遍历的时间复杂度为 $O(M + N)$，归并排序的时间复杂度同样为 $O(M + N)$。

- 空间复杂度：$O(M + N)$。我们需要使用额外的空间存储数组 `v1` 和 `v2`。