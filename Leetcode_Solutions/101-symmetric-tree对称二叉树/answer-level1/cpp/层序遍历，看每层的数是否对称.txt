思路：层序遍历二叉树，记录每层的数如果是回文数就对称
有两个要注意的地方：
    1. 层序遍历要记录每层的长度，也就是有几个节点
    2. 一个节点如果子树为空，节点的数记录为-1。如果不这样会有问题，空的节点一定要记录。
```
#include <queue>
#include <iostream>
class Solution {
public:
    int num[10000] = {0};
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        int i = 0;
        int curLayerLen = 1;
        int nextLayerLen = 0;
        while (!nodeQueue.empty()) {
            TreeNode *tmp = nodeQueue.front();
            nodeQueue.pop();
            if (tmp != NULL) {
                num[i++] = tmp->val;
                //std::cout << num[i-1] << ",";
                nodeQueue.push(tmp->left);
                nextLayerLen++;
                nodeQueue.push(tmp->right);
                nextLayerLen++;
            } else {
                num[i++] = -1;
                //std::cout << num[i-1] << ",";
            }
            curLayerLen--;
            if (curLayerLen == 0) {
                //std::cout << "everyLayerLen: " << i << std::endl;
                for (int j = 0, k = i-1; j < i / 2; j++, k--) {
                    if (num[j] != num[k]) {
                        return false;
                    }
                }
                i = 0;
                curLayerLen = nextLayerLen;
                nextLayerLen = 0;
            }
        }
        return true;
    }
};