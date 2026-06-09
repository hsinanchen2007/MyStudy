以root为根节点的路径的直径 = 其左右子树高度和 = dl + dr；
子树高度 = 两个子树更高的+1.
在求高度时会遍历各个结点，可以顺便计算以该结点为根节点对应的直径，用res保存最大值。

```
class Solution {       
private: int res = 0; 
public:
    int diameterOfBinaryTree(TreeNode* root) {        
        getDepth(root);
        return res;
    }
    inline int getDepth(TreeNode* croot){
        int d = 0; // 求子树高度
        if( croot ){
            int dl = getDepth(croot->left);
            int dr = getDepth(croot->right); 
            d = (dl>dr)? dl+1: dr+1;  
            res = res>(dl+dr)? res: (dl+dr);   
        }
        return d;
    }   
};
```
执行用时 :8 ms, 在所有 C++ 提交中击败了95.75%的用户
内存消耗 :21.9 MB, 在所有 C++ 提交中击败了15.95%的用户
我这个是很容易想到的方法，我去学习一下大神们都有什么更好的方法，同时也欢迎指正。

