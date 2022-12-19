### 解题思路
1、中序遍历二叉搜索树已经是升序的。
2、第一个节点出现，前一个值大于后一个值。将前一个值标记为first。
3、第二个节点出现，前一个值大于后一个值（此时first已不为空），将后一个值标记为second。
4、在遍历过程中需要保存当前节点的前一个节点，以此推断出first和second节点

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
private:
    TreeNode* firstNode = NULL;
    TreeNode* secondNode = NULL;
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> mystack;
        vector<int> ans;
        TreeNode* cur = root;
        TreeNode* pre = new TreeNode(INT_MIN);
        while(cur || !mystack.empty()){
            while(cur){
                mystack.push(cur);
                cur = cur->left;
            }
            cur = mystack.top();
            mystack.pop();
            if(firstNode == NULL && pre->val > cur->val){
                firstNode = pre;
            }
            if(firstNode!= NULL && pre->val > cur->val){
                secondNode = cur;
            }
            pre = cur;
            cur = cur->right;
        } 
        int val = firstNode->val;
        firstNode->val = secondNode->val;
        secondNode->val = val; 
    }
};
```