### 解题思路

深度优先搜索，如果左右子树有未覆盖的，优先设置摄像头覆盖；否则，如果左右子树有摄像头，将自己标志为已覆盖；最后如果都没有，则本结点未被覆盖。

### 代码

```cpp
class Solution {
private:
    int count = 0;
public:
    enum State { COVERED, UNCOVERED, CAMERA };
    
    int minCameraCover(TreeNode* root) {
        if(dfs(root) == UNCOVERED)
            count++;
        return count;
    }
    
    State dfs(TreeNode* root) {
        if(!root)
            return COVERED;

        State left = dfs(root->left);
        State right = dfs(root->right);
        
        if(left == UNCOVERED || right == UNCOVERED) {
            count++;
            return CAMERA;
        } else if(left == CAMERA || right == CAMERA) {
            return COVERED;
        }
        
        return UNCOVERED;
    }
};
```