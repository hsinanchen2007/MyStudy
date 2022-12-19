```
class Solution {
public:
    int maxDepth(Node* root) {
        int max_depth = 0;
        int depth = 0;
        if(root == NULL)
            return 0;
        for(Node* n:root->children)
        {
            depth = maxDepth(n);
            if(depth>max_depth)
                max_depth = depth;
        }
        return 1+max_depth;
    }
};
```
