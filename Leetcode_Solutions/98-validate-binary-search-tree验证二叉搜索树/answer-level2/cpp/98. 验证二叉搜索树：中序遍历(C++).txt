### 解题思路
* 中序遍历BST数可以得到单调递增的序列（题目严格要求不等）
* 第一个节点（最左字节点）不用比较，用cnt记录是否第一个数，
如果用INT_MIN比较第一个数，会遇到只包含[INT_MIN]的测试样例，报错。

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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;     // 堆栈实现中序遍历
        int cnt = 0;            // 标记节点数
        int val = -1;            // 中序遍历前一节点值

        while(!s.empty() || root) {
            while(root) {         // 中序遍历，左子节点非空，放入堆栈
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();            
            if(cnt > 0 && root->val > val){     // 如果当前节点值小于前一节点值，返回false       
                val = root->val;
            }
            else if(cnt == 0) {
                val = root->val;
                cnt++;
            }
            else 
                return false;
            root = root->right;
        }
        return true;
    }
};
```
![inorder.png](https://pic.leetcode-cn.com/9157e8e3154be73cd2efef0b37fc4d5074d28955d2b7325e09d00c6399982fb4-inorder.png)
