### 解题思路
    利用栈和数组进行实现； 
1.先依左子树遍历，将节点依次入栈。
2.到叶子节点后，出栈 栈顶元素； 判断当前元素的右子树是否为空，或者是否已处理； 如果已处理，则填入数组；
3.如果未处理，则将当前节点重新压入栈； 处理当前节点的右节点。

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* p;
        TreeNode* q;
        p = root;
        do {
            while(p != NULL) {      //沿左子树走到叶子节点
                s.push(p);
                p = p->left;
            }

            q = NULL;
            while(!s.empty()) {
                p = s.top();
                s.pop();
                if (p->right == q) {  //当前节点出栈，判断右子树为空或者已经处理；如果是的话，出栈
                    result.push_back(p->val);
                    q = p;
                } else {              //如果右子树还未处理，当前节点入栈，先处理右子树。
                    s.push(p);
                    p = p->right;
                    break;
                }
            }
        } while(!s.empty());
        return result;
    }
};
```