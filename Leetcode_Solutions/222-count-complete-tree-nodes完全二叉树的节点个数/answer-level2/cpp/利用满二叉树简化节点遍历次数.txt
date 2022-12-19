### 解题思路
使用通用的树的节点个数的求法也可以对本题求解， 但是却完全没有利用完全二叉树的性质， 而对于满二叉树， 可以通过高度直接计算出来其节点个数， 而计算树的高度的时间复杂度为 O(logn)，明显小于 O(n) 所以可以利用满二叉树简化节点的计算的时间复杂度。 
## 思路：
对于一颗完全二叉树， 其一定包含了若干满二叉树， 所以只要找出这些满二叉树即可。
如果检查任意节点的最左最右子树分支(边路分支)的高度， 如果左右相等， 那么此时子树就是一个满二叉树， 可以直接计算出来满二叉树的节点个数， 无需在遍历每一个节点
如果左右子树不相等， 就可以继续进行迭代， 来计算左右子树的节点个数

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
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int sum = 0;
        int lLevel = leftLevel(root -> left);
        int rLevel = rightLevel(root -> right);
        if(lLevel == rLevel){ // 满二叉树， 可以通过高度直接算出来节点个数， 并且完全二叉树的 leftNum <= rightNum
            sum = 2 * (pow(2, lLevel) - 1 ); // 满二叉树， 节点个数为 2 ^ h - 1， 所以左右两棵树节点个数为 2 * (2 ^ h - 1)
        }else{ // 不是满二叉树， 在进行递归
            sum += countNodes(root -> left) + countNodes(root -> right);
        }
        return sum + 1;
    }
    // 最左子树分支的高度
    int leftLevel(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int sum = 0;
        return leftLevel(root -> left) + 1;
    }

     // 最右子树分支的高度
    int rightLevel(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int sum = 0;
        return rightLevel(root -> right) + 1;
    }
};
```