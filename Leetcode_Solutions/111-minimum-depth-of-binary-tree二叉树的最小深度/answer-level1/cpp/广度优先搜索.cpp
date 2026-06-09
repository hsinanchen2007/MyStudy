### 解题思路
定义一个类型NodeWithDepth，包含node指针和当前深度。
使用队列实现广度优先搜索，遍历节点，遇到两个子节点都是空的节点，就说明到底了。
返回深度

执行用时 : 36 ms, 在所有 C++ 提交中击败了5.17%的用户。

### 代码

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
    struct NodeWithDepth
    {
        TreeNode *node;
        int depeth;  //方便记录每层深度
    };
    int minDepth(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        queue<NodeWithDepth> q; //队列实现广度优先搜索
        NodeWithDepth item;
        item.node = root;
        item.depeth = 1;
        q.push(item);
        TreeNode *point;
        int result(0);
        while ( !q.empty() )
        {
            NodeWithDepth temp = q.front();
            q.pop();
            result = temp.depeth;
            point = temp.node;
            if (!point->left && !point->right)
            {
                break;
            }
            if (point->left)
            {
                NodeWithDepth item;
                item.node = point->left;
                item.depeth = temp.depeth+1;
                q.push(item);
            }
            if (point->right)
            {
                NodeWithDepth item;
                item.node = point->right;
                item.depeth = temp.depeth+1;
                q.push(item);
            }
        }
        return result;
    }
};
```