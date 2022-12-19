### 解题思路
很多人说DP，的确这道题确实是有最优子结构，但是直接递归方法时间复杂度也是 O(n)， 缺点就是递归调用使得效率会慢些。 下面直接说思想：

写一个 dfs， 传入一个结点， 返回两个值:

1. 选择了对应结点的最优解， 记为 first
2. 没有选择对应结点的最优解， 记为 second

则当计算任何一层的最优解时， 假设本店的钱是a, 且已经获得了左右子结点的结果，记为 left, right。 则就可以构造本层的解：

1. 偷了本店：  r1 = a + left.second + right.second
2. 没有偷本店： 一共有4种情况，因为本店不偷，所有左右子店都可以选择偷和不偷， 2 × 2 = 4. 故有4种情况。

再看看代码就明白了。

### 代码

```cpp

class Solution {
public:
    pair<int, int> Rob(TreeNode* root)
    {
        if(root == nullptr) return make_pair(0, 0);
        int cur = root->val;
        auto left = Rob(root->left), right = Rob(root->right);

        int r1 = cur  + left.second + right.second;

        int r2 = max(left.first+right.first, left.second+right.second);
        r2 = max(r2, left.first+right.second);
        r2 = max(r2, left.second+right.first);

        return make_pair(r1, r2);
    }
    int rob(TreeNode* root) {
        auto r = Rob(root);
        return max(r.first, r.second);
    }
};
```