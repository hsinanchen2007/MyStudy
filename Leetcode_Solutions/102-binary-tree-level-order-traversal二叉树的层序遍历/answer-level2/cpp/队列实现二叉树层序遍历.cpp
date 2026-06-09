### 解题思路
利用队列FIFO的特性，每次遍历当前层节点的时候，将当前层节点的子节点入队。
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        queue<TreeNode*> queue;
        TreeNode* p=root;
        vector<vector<int>> res;
        
        queue.push(p);
        while(!queue.empty()){
            vector<int> temp={};
            // 当前层结点个数
            int length=queue.size();    
            for(int i=0; i<length; i++){
                p=queue.front();
                queue.pop();
                temp.push_back(p->val); 
                // 将当前层结点的子结点入队
                if(p->left) queue.push(p->left);
                if(p->right) queue.push(p->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};
```
### 结果
![屏幕快照 2020-03-18 下午7.22.34.png](https://pic.leetcode-cn.com/bee32a61fb19f504945b36a2bbe421cc5a1800f5448101c60a3e0094c364a96f-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-18%20%E4%B8%8B%E5%8D%887.22.34.png)
