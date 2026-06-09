对于满二叉树而言，二叉树的总节点数量肯定为奇数。而对于每个节点的左右子树而言，子树的节点数量也肯定为奇数。

满二叉树子树的状态转移规则如下：

```cpp
f(N) = f(i) + f(N - i - 1)      (i >= 1，i 为奇数，-1 为当前子树的根节点)
```

例如构建为 5 个节点的满二叉树时，情况有二：左子树为 3 个节点，右子树有 1 个节点；左子树有 1 个节点，右子树有 3 个节点。可以看到实际上是存在重复构建相同数量节点子树的情况。

因此，可以利用后序遍历自下而上构建满二叉树，即先构建节点数量为 1 的子树，后构建节点数量为 3 的子树，再构建节点数量为 5 的子树，直至构建 N 个节点的满二叉树。在每构建一个数量级的节点数量子树时，同时使用 map 记录节点个数与其所有可能的满二叉树形态，减少构建重复的满二叉树。

时间复杂度 O(n)，空间复杂度 O(n)。

* 示例 :

```cpp
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
    vector<TreeNode*> allPossibleFBT(int N) 
    {
        if (N % 2 == 0)
        {
            return {};
        }

        unordered_map<int, vector<TreeNode*>> TreeMap;
        TreeNode* pNode = new TreeNode(0);
        TreeMap[1] = {pNode};

        for (int i = 3; i <= N; i += 2)
        {
            for (int j = 2; j < i; j += 2)
            {
                for (auto LeftNode : TreeMap[j - 1])
                {
                    for (auto RightNode : TreeMap[i - j])
                    {
                        TreeNode* pNode = new TreeNode(0);
                        pNode->left = LeftNode;
                        pNode->right = RightNode;
                        TreeMap[i].push_back(pNode);                       
                    }
                }
            }
        }

        return TreeMap[N];
    }
};
```
