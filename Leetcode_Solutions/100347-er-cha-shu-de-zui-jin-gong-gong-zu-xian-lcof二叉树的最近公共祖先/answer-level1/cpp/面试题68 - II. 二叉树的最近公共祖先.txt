注意是二叉树，不是二叉搜索树
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

 //1. 递归解法
 // 实现了一个功能能强大的函数，对于pq均没在树中，或只有一个在树中的情况也有考虑（2，3）
 // 这个函数实现到功能：
 // - 在以root为根结点到树中
 // -- 1. 如果p和q同时存在，则寻找到最小公共祖先
 // -- 2. 如果p和q只有一个存在，则寻找到这个p或q
 // -- 3. 如果都不存在，返回 NULL
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
        if (root == p || root == q)  //当找到p或q时，返回p或q
            return root;
        
        auto l = lowestCommonAncestor(root->left, p, q);
        auto r = lowestCommonAncestor(root->right, p, q);

        if (l && !r)      //p或q出现在了左，没出现在右，返回在左边找着的 l
            return l;       //（l是p和q中先出现的，如果另一个也存在树中，l必是其祖先，也是最小公共祖先）
        else if (r && !l) //p或q出现在了右，没出现在左，返回在右边找着的 r（r是p和q中先出现的）
            return r;                  
        else if (l && r)  // 说明 p 和 q 一个在左，一个在右返回root （root是最小公共祖先）   
            return root;  
        else             // !r && !l  pq均不在左右子树中，返回NULL（没找着）
            return NULL;  
    }
};


// // 2. 寻找根到这两个节点到路径，求最后一个公共节点
// class Solution {
// private:
//     bool getPath(TreeNode * root, TreeNode * node, vector<TreeNode *> & path) {
		
//         if (root ==  NULL) return false;
        
//         path.push_back(root); //先序，先push进去，在左子树中找，没找着接着在右子树中找，都没找着就pop
		
//         if (root == node) return true;

// 		bool found = false;
//         found = getPath(root->left, node, path);		
//         if (!found) 
//             found = getPath(root->right, node, path);
// 		if (!found)
// 			path.pop_back();		
// 		return found;
//     }

// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         vector< TreeNode * > path1, path2;
//         getPath(root, p, path1);
//         getPath(root, q, path2);

//         TreeNode * ancestor = root;
//         for (int i = 0; i < min(path1.size(), path2.size()); i++) {
//             if (path1[i] == path2[i])
//                 ancestor = path1[i];
//             else
//                 break;
//         }
//         return ancestor;
//      }
// };



```