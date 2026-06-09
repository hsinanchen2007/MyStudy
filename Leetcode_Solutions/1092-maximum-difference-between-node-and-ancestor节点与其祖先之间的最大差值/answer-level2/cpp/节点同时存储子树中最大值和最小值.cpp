### 解题思路
从叶子节点开始遍历树，维护一个map，里面存储以当前节点为根的子树中的最大值和最小值，对于一个节点来说，先得到他的左子树和右子树共同的最大值和最小值，利用他们之间的绝对值更新最大差值。详解见注释。
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
    struct Node  //结构体，存储以当前节点为根的树的最大值和最小值
    {
        int min;
        int max;
        Node(int x, int y) : min(x), max(y) {}
    };
    map<TreeNode*, Node*> nodeVal;  //map存储树节点及对应的Node
    int ans = 0;
    Node* minAndmax(Node* x, Node* y)  //得到左子树和右子树共同的最大值和最小值
    {
        if(x && y)  //两个Node都不为空
        {
        int mins = min(x -> min, y -> min);
        int maxs = max(x -> max, y -> max);
        return new Node(mins, maxs);
        }
        else
        return x == NULL ? y : x;
    }
    Node* minmax(Node* x, int y)  //得到一个树节点的最大值和最小值
    {
        return new Node(min(y, x -> min), max(y, x -> max));
    }
    void maxDiff(TreeNode* root)
    {
        if(root != NULL)
        {
           if(root -> left == NULL && root -> right == NULL)  //叶子结点，默认最大值和最小值相等
           {
              Node* node = new Node(root -> val, root -> val);
              nodeVal[root] = node;
           }
            maxDiff(root -> left);  //得到左子树的Node
            maxDiff(root -> right);  //得到右子树的Node
            //得到左子树和右子树综合起来的Node
            Node* node = minAndmax(nodeVal[root -> left], nodeVal[root -> right]);
            if(node)
            {
            ans = max(ans, abs(root -> val - node -> min));  //更新ans
            ans = max(ans, abs(root -> val - node -> max));
            nodeVal[root] = minmax(node, root -> val);
            }
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        maxDiff(root);
        return ans;
    }
};
```