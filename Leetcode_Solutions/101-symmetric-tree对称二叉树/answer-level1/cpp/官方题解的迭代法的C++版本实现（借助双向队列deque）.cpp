```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//方法一：递归法
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
     
//         return isMirror(root, root);
//     }   
    
//     bool isMirror(TreeNode* t1, TreeNode* t2) {
//         if (t1 == nullptr && t2 == nullptr) return true; //20和22行是作为递归终止条件出现的，
//所以要直接写返回true，这和下面的迭代法的第53行的代码有明显不同！！！
        
//         if (t1 == nullptr || t2 == nullptr) return false;
        
//         return ( t1->val == t2->val) 
//             && isMirror( t1->right, t2->left)
//             && isMirror( t1->left, t2->right);
//     }
// };
```



```
//方法二：迭代法（借助队列，和BFS相似，但是插入顺序有不同）
#include <deque>
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        deque<TreeNode*> d;
        d.push_back(root);
        d.push_back(root);
        
        while( !d.empty() ) {
            TreeNode* t1 = d.front();
            d.pop_front();
            TreeNode* t2 = d.front();
            d.pop_front();
            
            if( t1 == nullptr && t2 == nullptr) continue; //注意！这里是continue，不是直接递归的时候那样可以直接返回true了！！！
            
            if( t1 == nullptr || t2 == nullptr) return false;
            
            if(t1->val != t2->val) return false;
            
            d.push_back(t1->right);
            d.push_back(t2->left);
            d.push_back(t1->left);
            d.push_back(t2->right);
        }
     
        return true;
    }   
};

```






















