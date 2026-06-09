### 解题思路

递归终止条件： 只要有一个节点为NULL就停止，之后判断是不是只有一个节点为空，

每次递归的时候，就判断是不是当前的值是不是相同，如果相同，就递归的判断left和right，

否则返回false

### 代码

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //递归终止条件, 又一个为空
        if (p == NULL || q == NULL){
            if ( p != NULL || q != NULL) return false;
            return true;
        }
        if (p->val == q->val ){
            if ( isSameTree(p->left, q->left) && isSameTree(p->right, q->right)){
                return true;
            }
        }
        return false;
    }
    
};
```