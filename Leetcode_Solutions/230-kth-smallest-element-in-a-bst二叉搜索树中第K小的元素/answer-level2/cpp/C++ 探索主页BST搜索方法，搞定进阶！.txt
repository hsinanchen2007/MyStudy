#### 其它方法请移步blog：[[每日一题] 133. 二叉搜索树中第K小的元素(BST树、递归、搜索技巧、多方法）](https://blog.csdn.net/yl_puyu/article/details/104267581)

####  [**LeetCode探索   二叉搜索树**](https://leetcode-cn.com/explore/learn/card/introduction-to-data-structure-binary-search-tree/66/conclusion/182/) 对该种搜索方法进行了诠释，**真的绝妙的思想。**
![image.png](https://pic.leetcode-cn.com/0b31131e9c743dccfaed741b3a38d73e1fc5e9b6d31d9f21261018ee098186dc-image.png)
![image.png](https://pic.leetcode-cn.com/707e5e67fdcf6fd64ad4d5620ef8c44900fe1447790bae0d991dc177fd15e2f0-image.png)

先来看个分治：
再来看一种分治法的思路，由于 ```BST``` 的性质，可以快速定位出第```k```小的元素是在左子树还是右子树，首先计算出左子树的结点个数总和 ```cnt```，如果```k```小于等于左子树结点总和 ```cnt```，说明第```k```小的元素在左子树中，直接对左子结点调用递归即可。如果```k```大于 ```cnt+1```，说明目标值在右子树中，对右子结点调用递归函数，注意此时的```k```应为 ```k-cnt-1```，应为已经减少了```cnt+1``` 个结点。如果```k```正好等于 ```cnt+1```，说明当前结点即为所求，返回当前结点值即可。

参见代码如下：
```cpp
// 执行用时 :20 ms, 在所有 C++ 提交中击败了88.64%的用户
// 内存消耗 :22.1 MB, 在所有 C++ 提交中击败了5.23%的用户

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
    int kthSmallest(TreeNode* root, int k) {
        int cnt = count(root->left);
        if (k <= cnt) 
            return kthSmallest(root->left, k);
        else if (k > cnt + 1) 
            return kthSmallest(root->right, k - cnt - 1);
        return root->val;
    }
    int count(TreeNode* node) {
        if (!node) 
            return 0;
        return 1 + count(node->left) + count(node->right);
    }
};
```
这道题的 **进阶** 中说假设该 ```BST``` 被修改的很频繁，而且查找第```k```小元素的操作也很频繁，问如何优化。其实最好的方法还是像上面的解法那样利用分治法来快速定位目标所在的位置，但是每个递归都遍历左子树所有结点来计算个数的操作并不高效，所以应该修改原树结点的结构，使其保存包括当前结点和其左右子树所有结点的个数，这样就可以快速得到任何左子树结点总数来快速定位目标值了。定义了新结点结构体，然后就要生成新树，还是用递归的方法生成新树，注意生成的结点的 ```count``` 值要累加其左右子结点的 ```count``` 值。然后在求第```k```小元素的函数中，先生成新的树，然后调用递归函数。在递归函数中，不能直接访问左子结点的 ```count``` 值，因为左子节结点不一定存在，所以要先判断，如果左子结点存在的话，那么跟上面解法的操作相同。如果不存在的话，当此时```k```为```1```的时候，直接返回当前结点值，否则就对右子结点调用递归函数，```k```自减```1```。

参见代码如下：
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


 // Follow up
class Solution {
public:
    struct MyTreeNode {
        int val;
        int count;
        MyTreeNode *left;
        MyTreeNode *right;
        MyTreeNode(int x) : val(x), count(1), left(NULL), right(NULL) {}
    };
    
    MyTreeNode* build(TreeNode* root) {
        if (!root) 
            return NULL;
        MyTreeNode* node = new MyTreeNode(root->val);
        node->left = build(root->left);
        node->right = build(root->right);
        if (node->left) 
            node->count += node->left->count;
        if (node->right) 
            node->count += node->right->count;
        return node;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        MyTreeNode *node = build(root);
        return helper(node, k);
    }
    
    int helper(MyTreeNode*& node, int k) {
        if (node == nullptr)
            return 0;
        if (node->left) {
            int cnt = node->left->count;
            if (k <= cnt) 
                return helper(node->left, k);
            else if (k > cnt + 1) 
                return helper(node->right, k - 1 - cnt);
            return node->val;
        } 
        else {
            if (k == 1) 
                return node->val;
            return helper(node->right, k - 1);
        }
    }
};
```
