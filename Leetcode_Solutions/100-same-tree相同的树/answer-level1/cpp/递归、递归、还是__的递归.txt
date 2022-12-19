### 解题思路
条件判断好就好了

### 代码

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        return (p->val == q->val) 
                && (isSameTree(p->left,q->left) 
                && isSameTree(p->right,q->right));
    }
};
```
![深度截图_选择区域_20200330164923.png](https://pic.leetcode-cn.com/91eb10faf3a06c826a9466b6a187ce8718bcf17fe210ef38de0df69f89a6e0a6-%E6%B7%B1%E5%BA%A6%E6%88%AA%E5%9B%BE_%E9%80%89%E6%8B%A9%E5%8C%BA%E5%9F%9F_20200330164923.png)
