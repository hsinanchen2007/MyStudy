### 解题思路
用的是level order traversal. 用空间换取了时间。
### 代码

```
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        std::queue<TreeNode*> myqueue;
        myqueue.push(root);
        int ans = 0;
        while(!myqueue.empty()){
            if(myqueue.front()->left)
                myqueue.push(myqueue.front()->left);
            if(myqueue.front()->right)
                myqueue.push(myqueue.front()->right);
            ans++;
            myqueue.pop();
        }
        return ans;
    }
};
```