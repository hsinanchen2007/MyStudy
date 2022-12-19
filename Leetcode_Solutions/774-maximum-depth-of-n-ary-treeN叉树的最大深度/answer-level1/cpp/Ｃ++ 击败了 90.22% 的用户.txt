### 代码

```cpp
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root)return 0;

        int res = 0;
        for(auto child:root->children)
            res = max(res,maxDepth(child));

        return ++res;
    }
};
```