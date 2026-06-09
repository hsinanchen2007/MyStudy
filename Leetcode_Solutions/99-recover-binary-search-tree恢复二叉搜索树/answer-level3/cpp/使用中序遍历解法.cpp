### 解题思路
**问题**：两个结点错误交换
**如何找出这两个结点**：利用中序遍历
**两种情况**：一种是错误结点相邻，二是错误结点不相邻

        1. 相邻的情况下，只需要判断出这一结点值小于上个结点的值时将两者val互换即可
        2. 不相邻情况下，说明大的结点值被交换到前面了，所以第一次遇到异常情况保存结点值大的
           结点，第二次遇到异常保存结点值小的结点，然后将两个保存的结点值互换即可。


**解决问题**：转换node中value值即可

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
    void recoverTree(TreeNode* root) {
    TreeNode* firstNode = nullptr;
    TreeNode* secondNode = nullptr;
    TreeNode* preNode = nullptr;
    stack<TreeNode*> sk;
    long pre = LONG_MIN ;
    int temp;
    while(root != nullptr || !sk.empty()){
        while(root != nullptr){
            sk.push(root);
            root = root -> left;
        }
        root = sk.top();
        sk.pop();
        if(root -> val <= pre && firstNode == nullptr) {
                firstNode  = preNode;
            }
        if(root -> val <= pre && firstNode != nullptr) {
                secondNode = root;
            }
        preNode = root;
        pre     = root -> val;
        root    = root -> right;
    }
    temp              = firstNode -> val;
    firstNode -> val  = secondNode -> val;
    secondNode -> val = temp;
    }  
};

```