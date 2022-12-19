### 思路
对二叉搜索树中序遍历，每次遍历的节点的值都严格大于前一个访问过的节点的值。因此，用变量last记录中序遍历过程中最后一个访问节点的值，然后与当前访问节点的值进行比较：

 

* 如果当前节点的值大于last，则更新last为当前节点的值，随后继续进行判断。
    
* 否则说明不是二叉搜索树，返回false。

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long long last = LLONG_MIN;     // 用long long 的最小值，防止存在INT_MIN的节点
        return inorder(root,last);
    }
    bool inorder(TreeNode* root, long long& last){
        if(!root) return true;
        if(inorder(root->left, last) && (root->val > last)){
            last = root->val;
            return inorder(root->right, last);
        }  
        return false;
    }
};
```