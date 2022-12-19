### 解题思路
此题与 [100.相同的树](https://leetcode-cn.com/problems/same-tree/) 类似， 做这道题之前可以先做 100 号问题
如果左右子树对称， 可以很容易的通过观察看到， 以根节点为轴线， 左右两课树互为镜像， 所以只要检查左跟节点的右两棵树是否为镜像即可

![image.png](https://pic.leetcode-cn.com/875588e23c362cfd5b2b55fd8e3407a167bf6d87cd1a147fa876ec91ef5cc4dd-image.png)

互为镜像的两棵树满足一下条件，以最简单的各有3个节点的两棵树为例(图中红框) 即两棵树的根**节点相等**， 并且以一个树的的左子树与另一个子树的右子树**节点相等**。

注意这里的**节点相等**包含一下几种情况：
- 节点都为空
- 节点都不为空， 并且其值相等

所以**节点不相等**包含一下几种情况：
- 一个为空， 一个不为空
- 都不为空， 单数值不相等

所以只要完成一个函数进行上述判断即可， 如果发现该树对称， 就继续校验子树


#### 递归结束条件
- 发现**节点不相等**
- 两棵树都都为空， 其也是一种**节点相等**的情况
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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return __isSymmetric(root -> left, root -> right);
    }

    // 判断 p, q 两棵树是否互为镜像即一个树的的左子树与另一个子树的右子树是否相等
    bool __isSymmetric(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL ){ // 节点都为空
            return true;
        }
        if(p == NULL && q != NULL || p != NULL && q == NULL){ // 一个为空， 一个不为空
            return false;
        }
        if(p -> val != q -> val){ // 都不为空， 单数值不相等
            return false;
        }else{ // 节点都不为空， 并且其值相等， 继续校验子树, 一个树的的左子树与另一个子树的右子树是否相等
            return __isSymmetric(p -> left, q -> right) && __isSymmetric(p -> right, q -> left);
        }
        return true;
    }
};
```