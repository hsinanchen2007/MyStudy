- 边界条件
- 如何构建当前root的解
- 用递归的f(root->child)求解出子树高度，并选择其中最大值`maxd + 1`作为自己的高度返回。

```cpp

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int maxd = 0;
        for(auto e : root->children){
            maxd = max(maxd, maxDepth(e));
        }
        return maxd + 1;
    }
};
```