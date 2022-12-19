思路是我们可以对每一层的节点都进行编号（空节点也需编号），第一个节点为1，第二个为2. 这样每层的宽度就是该层最右边的节点编号减去最左边节点编号再加1.
另外在遍历当前层的时候，我们将下一层的节点编号后放入一个数组里面。
循环遍历这个数组。
编号有个规矩就是：因为是二叉树，所以下一层满节点的情况下，节点数目就是当前层节点数的2倍。
所以一个编号为'x'的节点的两个子节点可以分别编号为'2*x - 1'; '2 * x'

一般来讲这样就可以了，但是这个题目有个恶心的例子，全部节点都只有右子树。按照上面的编码，后面的编号就要爆炸。所以做一个优化就是每当对下一层的节点进行编号的时候，减去下一层最左边的编号减1的数。这样就可以保证编号不会超出题目要求的int的范围。

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct MyNode {
    TreeNode *treeNode;
    int treePos;
    MyNode(int pos, TreeNode *node) : treePos(pos), treeNode(node) {}
};

class Solution {
public:
    
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        vector<MyNode> arr;
        int maxWidth = 0;
        MyNode n = MyNode(1, root);
        arr.emplace_back(n);
        
        while(arr.size() > 0) {
            vector<MyNode> tempArray;
            int left = 0, i = 0, nextStart = -1;
            for (auto node : arr) {
                if (i == 0) {
                    left = node.treePos;
                }
                if (node.treeNode->left != NULL) {
                    if (nextStart == -1) {
                        nextStart = node.treePos * 2 - 2;
                    }
                    tempArray.emplace_back(node.treePos * 2 - 1 - nextStart, node.treeNode->left);
                } 
                if (node.treeNode->right != NULL) {
                    if (nextStart == -1) {
                        nextStart = node.treePos * 2 - 1;
                    }
                    tempArray.emplace_back(node.treePos * 2 - nextStart, node.treeNode->right);
                }
                if (i == arr.size()-1) {
                    maxWidth = max(node.treePos - left + 1, maxWidth);
                }
                i++;
            }
            arr.swap(tempArray);
        }
        return maxWidth;
    }
};
```